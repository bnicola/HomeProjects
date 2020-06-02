#include <QApplication>

#include "HandwritingRecognition.hpp"


int main(int argc, char** argv)
{
   QApplication app(argc, argv);
   HandwritingRecognition hwR;

   hwR.show();

   app.exec();
}
