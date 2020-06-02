#include "HandwritingRecognition.hpp"
#include <QMessageBox>
#include <fstream>
#include <QTextStream>

HandwritingRecognition::HandwritingRecognition()
      : minX_(0xFFFFFFFF),
        minY_(0xFFFFFFFF),
        maxX_(0),
        maxY_(0)
{
   setupUi(this);

   width_  = 256;
   height_ = 256;

   image_ = new double*[28];
   for (int i = 0; i < 28; ++i)
   {
      image_[i] = new double[28];
   }

   ClearImage();

   srand(static_cast <unsigned> (time(0)));
   quint32 num_of_inputs  = 784;
   quint32 num_of_hidden  = 200;
   quint32 num_of_outputs = 47;
   learning_rate_ = 0.1;

   Matrix already_wih;
   Matrix already_who;
   bool   already_knows_somthing = CheckPreviousLearning(already_wih, already_who);

   nn_ = new NeuralNetwork(num_of_inputs, num_of_hidden, num_of_outputs, learning_rate_, already_wih, already_who, already_knows_somthing);

   QRectF drawingBoard(0.0, 0.0, width_, height_);
   drawingBoardView_->setSceneRect(drawingBoard);
   qreal viewHeight = drawingBoard.height();
   qreal viewWidth  = drawingBoard.width();

   drawingBoardView_->setScene(&drawingBoardScene_);
   drawingBoardView_->scale(1, 1);
   drawingBoardView_->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
   drawingBoardView_->setOptimizationFlags(QGraphicsView::DontClipPainter | QGraphicsView::DontSavePainterState | QGraphicsView::DontAdjustForAntialiasing);
   drawingBoardView_->fitInView(drawingBoardScene_.sceneRect());
   drawingBoardScene_.setItemIndexMethod(QGraphicsScene::NoIndex);

   drawingBoardView_->setFixedSize(viewWidth, viewHeight);
   drawingBoardView_->setSceneRect(0, 0, viewWidth, viewHeight);

   connect(&drawingBoardScene_, SIGNAL(mouseClick(QPointF)), this, SLOT(MouseClick(QPointF)));
   connect(&drawingBoardScene_, SIGNAL(FinishedDrawing()), this, SLOT(FinishedDrawing()));
   connect(clearBoardButton_, &QPushButton::clicked, this, &HandwritingRecognition::ClearBoard);
   connect(train_, &QPushButton::clicked, this, &HandwritingRecognition::Train);
   connect(correctMe_, SIGNAL(clicked()), this, SLOT(CheckForTraining()));

   symbols_.append({0, "0"});
   symbols_.append({1, "1"});
   symbols_.append({2, "2"});
   symbols_.append({3, "3"});
   symbols_.append({4, "4"});
   symbols_.append({5, "5"});
   symbols_.append({6, "6"});
   symbols_.append({7, "7"});
   symbols_.append({8, "8"});
   symbols_.append({9, "9"});
   symbols_.append({10, "+"});
   symbols_.append({11, "-"});
   symbols_.append({12, "*"});
   symbols_.append({13, "\\"});
   symbols_.append({14, "="});
   symbols_.append({15, "A"});
   symbols_.append({16, "B"});
   symbols_.append({17, "C"});
   symbols_.append({18, "D"});
   symbols_.append({19, "E"});
   symbols_.append({20, "F"});
   symbols_.append({21, "G"});
   symbols_.append({22, "H"});
   symbols_.append({23, "I"});
   symbols_.append({24, "J"});
   symbols_.append({25, "K"});
   symbols_.append({26, "L"});
   symbols_.append({27, "M"});
   symbols_.append({28, "N"});
   symbols_.append({29, "O"});
   symbols_.append({30, "P"});
   symbols_.append({31, "Q"});
   symbols_.append({32, "R"});
   symbols_.append({33, "S"});
   symbols_.append({34, "T"});
   symbols_.append({35, "U"});
   symbols_.append({36, "V"});
   symbols_.append({37, "W"});
   symbols_.append({38, "X"});
   symbols_.append({39, "Y"});
   symbols_.append({40, "Z"});
	symbols_.append({41, "/" });
	symbols_.append({42, "!" });
	symbols_.append({43, "@" });
	symbols_.append({44, "#" });
	symbols_.append({45, "%" });
	symbols_.append({46, "&" });
}


void HandwritingRecognition::ReadTestData(QString testDataFile)
{
   QVector<NeuralNetwork::Symbol> test_symbols = nn_->ReadTestData(testDataFile);
   for (uint32_t i = 0; i < test_symbols.size(); i++)
   {
      Matrix target_matrix(41, 1, 0.000001);
      target_matrix.SetValue(test_symbols.at(i).value, 0, 0.999999);
      target_matrix.Print();
      std::vector<float> target = target_matrix.ToArray();

      Matrix input_matrix(0, 0);
      std::vector<float> input = input_matrix.ToArray();

      for (uint32_t j = 0; j < 784; j++)
      {
         input.push_back(test_symbols.at(i).pixels[j]);
      }
      std::vector<float> result = nn_->Ask(input);
      uint32_t digit            = nn_->Maximum(result);
      QApplication::processEvents();
   }
}


void HandwritingRecognition::ClearBoard()
{
   foreach(QGraphicsItem * item, drawingBoardScene_.items())
   {
      DrawingPen* penItem = dynamic_cast<DrawingPen*>(item);

      if (penItem)
      {
         delete penItem;
      }
   }

   minX_ = 0xFFFFFFFF;
   minY_ = 0xFFFFFFFF;
   maxX_ = 0;
   maxY_ = 0;

   ClearImage();
}


void HandwritingRecognition::WhatIsIt()
{
   std::vector<float> input  = SerializeImage();
   std::vector<float> result = nn_->Ask(input);

   quint32 digit = nn_->Maximum(result);
   correctAnswer_->setText(symbols_.at(digit).label);
   confidenceOf_->setText("With Confidence " + QString::number(result.at(digit) * 100, 'f', 2) + "%");
   QApplication::processEvents();
}


void HandwritingRecognition::Train()
{
   nn_->SetLearningRate(learninRateSpinBox_->value());
   nn_->SetDropRate(dropRateSpinBox_->value());
   QVector<NeuralNetwork::Symbol> symbols = nn_->ReadTrainingData("Symbol_Training_Data.csv");
   quint32  maxEpoch                      = epoch_->value();
   uint32_t progressIndex                 = 0;
   float    index2                        = 0;
   trainingProgress_->setMaximum(maxEpoch * symbols.size());
   for (int epoch = 0; epoch < maxEpoch; epoch++)
   {
      for (int i = 0; i < symbols.size(); i++)
      {
         uint32_t randomSymbol        = (rand()) % symbols.size();
         NeuralNetwork::Symbol symbol = symbols.at(randomSymbol);

         Matrix target_matrix(47, 1, 0.000001);
         target_matrix.SetValue(symbol.value, 0, 0.999999);
         std::vector<float> target = target_matrix.ToArray();
         Matrix input_matrix(0, 0);
         std::vector<float> input = input_matrix.ToArray();
         uint32_t index           = 0;
         for (int j = 0; j < 784; j++)
         {
            input.push_back(symbol.pixels[index++]);
         }

         QApplication::processEvents();

         nn_->Train(input, target);
         trainingProgress_->setValue(progressIndex++);
         if (progressIndex % 400 == 0)                        // update coefficients every now and then
         {
            Matrix whi = nn_->Wih();
            Matrix who = nn_->Who();

            SaveWeightToFile(whi, who);
         }

      }

      Matrix whi = nn_->Wih();
      Matrix who = nn_->Who();

      SaveWeightToFile(whi, who);

   }
}


void HandwritingRecognition::CheckForTraining()
{
   std::vector<float> input = SerializeImage();
   Matrix  target_matrix(47, 1, 0.00001);
   quint32 index = 0;
   bool found    = false;
   for (int i = 0; i < symbols_.size() && found == false; i++)
   {
      if (symbols_.at(i).label.toLower() == correctAnswer_->text().toLower())
      {
         index = i;
         found = true;
      }
   }
   target_matrix.SetValue(index, 0, 0.99999);
   std::vector<float> target = target_matrix.ToArray();

   Matrix input_matrix(0, 0);

   Matrix whi = nn_->Wih();
   Matrix who = nn_->Who();

   nn_->Train(input, target);
   CreateSymbolDataFile(input, target);
   QApplication::processEvents();
   SaveWeightToFile(whi, who);

}


void HandwritingRecognition::CreateSymbolDataFile(std::vector<float> input, std::vector<float> target)
{
   QFile symbolFile("Symbol_Training_Data.csv");
   QTextStream out(&symbolFile);

   if (symbolFile.open(QIODevice::Text | QIODevice::Append) == true)
   {
      QString symbolVal = QString::number(nn_->Maximum(target));
      out << symbolVal << ",";
      for (int i = 0; i < input.size(); i++)
      {
         if (input.at(i) < 0.05)
         {
            out << "0";
         }
         else
         {
            out << "255";
         }
         if (i != input.size() - 1)
         {
            out << ",";
         }
      }
      out << "\n";
   }
}


void HandwritingRecognition::TrainLetters()
{

}


void HandwritingRecognition::MouseClick(QPointF point)
{
   DrawingPen* pen = new DrawingPen(drawingBoardScene_);

   pen->SetPosition(point.x(), point.y());

   double   scale  = width_ / 28;
   uint32_t column = point.x() / scale;
   uint32_t row    = point.y() / scale;
   minX_ = (minX_ > point.x()) ? point.x() : minX_;
   minY_ = (minY_ > point.y()) ? point.y() : minY_;

   maxX_ = (maxX_ < point.x()) ? point.x() : maxX_;
   maxY_ = (maxY_ < point.y()) ? point.y() : maxY_;
   if ((row > 0) && (column > 0) && (row < 27) && (column < 27))
   {
      image_[row][column]     = 0.9999;
      image_[row][column - 1] = 0.9999;
      image_[row][column + 1] = 0.9999;
      image_[row - 1][column] = 0.9999;
      image_[row + 1][column] = 0.9999;

      Matrix input_matrix(0, 0);
      std::vector<float> input = input_matrix.ToArray();

      for (int i = 0; i < 28; i++)
      {
         for (int j = 0; j < 28; j++)
         {
            input.push_back(image_[i][j]);
         }
      }
      std::vector<float> result = nn_->Ask(input);
      quint32 digit             = nn_->Maximum(result);
      correctAnswer_->setText(symbols_.at(digit).label);
      confidenceOf_->setText("With Confidence " + QString::number(result.at(digit) * 100) + "%");
      bool found     = false;
      QString symbol = "";
      for (int j = 0; j < symbols_.size() && found == false; j++)
      {
         if (symbols_.at(j).index == digit)
         {
            found  = true;
            symbol = symbols_.at(j).label;
         }
      }
      QApplication::processEvents();
   }
}


void HandwritingRecognition::FinishedDrawing()
{
   Matrix input_matrix(0, 0);

   std::vector<float> input = input_matrix.ToArray();

   for (uint32_t i = 0; i < 28; i++)
   {
      for (uint32_t j = 0; j < 28; j++)
      {
         input.push_back(image_[i][j]);
      }
   }

   WhatIsIt();
}


bool HandwritingRecognition::CheckPreviousLearning(Matrix& already_wih, Matrix& already_who)
{
   bool wih_exists             = false;
   bool who_exists             = false;
   bool already_knows_somthing = false;
   std::string   line;
   std::ifstream wih_file;
   std::ifstream who_file;

   std::vector<std::string> data;

   wih_file.open("wih.txt");
   wih_file.seekg(0);
   if (wih_file.is_open() == true)
   {
      wih_exists = true;
      size_t lines_count = 0;
      size_t num_of_cols = 0;
      while (std::getline(wih_file, line))
      {
         std::vector<std::string> line_comp = split(line, ",");
         num_of_cols = line_comp.size();
         lines_count++;
         for (int i = 0; i < num_of_cols; i++)
         {
            data.push_back(line_comp.at(i));
            QApplication::processEvents();
         }

      }
      wih_file.close();
      already_wih.SetDimensions(lines_count, num_of_cols);
   }

   wih_file.open("wih.txt");
   wih_file.seekg(0);
   if (wih_file.is_open() == true)
   {
      int index = 0;
      for (size_t i = 0; i < already_wih.Rows(); i++)
      {
         for (size_t j = 0; j < already_wih.Cols(); j++)
         {
            already_wih.SetValue(i, j, atof(data.at(index++).c_str()));
            QApplication::processEvents();
         }
      }
   }
   data.clear();

   who_file.open("who.txt");
   who_file.seekg(0);
   if (who_file.is_open() == true)
   {
      who_exists = true;
      size_t lines_count = 0;
      size_t num_of_cols = 0;
      while (std::getline(who_file, line))
      {
         std::vector<std::string> line_comp = split(line, ",");
         num_of_cols = line_comp.size();
         lines_count++;
         QApplication::processEvents();
         for (int i = 0; i < line_comp.size(); i++)
         {
            data.push_back(line_comp.at(i));
            QApplication::processEvents();
         }
      }
      who_file.close();
      already_who.SetDimensions(lines_count, num_of_cols);
   }

   who_file.open("who.txt");
   who_file.seekg(0);
   if (who_file.is_open() == true)
   {
      int index = 0;
      for (size_t i = 0; i < already_who.Rows(); i++)
      {
         for (size_t j = 0; j < already_who.Cols(); j++)
         {
            already_who.SetValue(i, j, atof(data.at(index++).c_str()));
            QApplication::processEvents();
         }
      }
   }

   already_knows_somthing = wih_exists && who_exists;

   return already_knows_somthing;

}


std::vector<std::string> HandwritingRecognition::split(std::string str, std::string delimiter)
{
   std::vector<std::string> matches;
   int pos = 0;
   if (str.find(delimiter) != -1)
   {
      while (str.length() > 0 && pos != -1)
      {
         pos = str.find(delimiter);
         if (pos != -1)
         {
            std::string token = str.substr(0, pos);
            matches.push_back(token);
            str = str.substr(pos + delimiter.size(), str.length());
         }
         else
         {
            matches.push_back(str);
         }
      }
   }

   return matches;
}


std::vector<float> HandwritingRecognition::SerializeImage()
{
   std::vector<float> pixels;

   for (size_t i = 0; i < 28; i++)
   {
      for (size_t j = 0; j < 28; j++)
      {
         pixels.push_back(image_[i][j]);
      }
   }

   return pixels;
}


void  HandwritingRecognition::ClearImage()
{
   for (size_t i = 0; i < 28; i++)
   {
      for (size_t j = 0; j < 28; j++)
      {
         image_[i][j] = 0.001;
      }
   }
}


void HandwritingRecognition::DrawSymbol(std::vector<float> data)
{
   int index = 0;

   for (int i = 0; i < 28; i++)
   {
      for (int j = 0; j < 28; j++)
      {
         if (data.at(index++) > 0.2)
         {
            printf("#");
         }
         else
         {
            printf("-");
         }
      }
      printf("\n");
   }
}


void HandwritingRecognition::SaveWeightToFile(Matrix wih, Matrix who)
{
   std::ofstream myfile1;

   myfile1.open("wih.txt", std::ios::out);
   if (myfile1.is_open() == true)
   {
      for (uint32_t i = 0; i < wih.Rows(); i++)
      {
         for (uint32_t j = 0; j < wih.Cols(); j++)
         {
            myfile1 << wih.Value(i, j) << ",";
         }
         myfile1 << std::endl;

      }
      myfile1.close();
      myfile1.flush();

   }

   std::ofstream myfile2;
   myfile2.open("who.txt", std::ios::out);
   for (uint32_t i = 0; i < who.Rows(); i++)
   {
      for (uint32_t j = 0; j < who.Cols(); j++)
      {
         myfile2 << who.Value(i, j) << ",";
      }
      myfile2 << std::endl;
   }
   myfile2.close();
   myfile2.flush();
}
