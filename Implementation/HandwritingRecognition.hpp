#ifndef __HAND_WRITEN_RECOGNITION_HPP__
#define __HAND_WRITEN_RECOGNITION_HPP__

#include "DrawingBoardScene.hpp"

#include <ui_HandwritingRecognition.h>
//#include "Matrix.hpp" "
#include "NeuralNetwork.hpp "
#include "DrawingPen.hpp "
#include <vector>
#include <time.h>
#include <fstream>

class HandwritingRecognition : public QMainWindow, public Ui::HandwritingRecognition
{
   Q_OBJECT

   public:
      struct Symbols
      {
         uint32_t index;
         QString  label;

      };

   public:
      HandwritingRecognition();

   public slots:
      void MouseClick(QPointF point);
      void FinishedDrawing();
      void ClearBoard();
      void WhatIsIt();
      void Train();

      void CheckForTraining();
      void CreateSymbolDataFile(std::vector<float> input, std::vector<float> target);
      void TrainLetters();

   private:
      std::vector<std::string> split(std::string str, std::string delimiter);

      std::vector<float> SerializeImage();

      bool CheckPreviousLearning(Matrix& already_wih, Matrix& already_who);

      void ClearImage();

      void DrawSymbol(std::vector<float> data);

      void SaveWeightToFile(Matrix wih, Matrix who);

      void ReadTestData(QString testDataFile);

      /* void FillupHiddenToOutputCoeff();

         void FillupInputToHiddenCoeff();*/

   private:
      DrawingBoardScene drawingBoardScene_;

      NeuralNetwork* nn_;

      double** image_;
      uint32_t width_;
      uint32_t height_;

      uint32_t minX_;
      uint32_t minY_;

      uint32_t maxX_;
      uint32_t maxY_;

      QList<Symbols> symbols_;

      float learning_rate_;

};


#endif //__HAND_WRITEN_RECOGNITION_HPP__
