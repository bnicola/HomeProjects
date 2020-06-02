PROJECT_DIR = ../..
TEMPLATE = app

TARGET = HandwritingRecognition

QT += opengl
QT += network
QT += script

CONFIG += console


INCLUDEPATH = $$PROJECT_DIR/Interface \
              $$PROJECT_DIR/Implementation
			  
SOURCES += $$PROJECT_DIR/Implementation/main.cpp \
           $$PROJECT_DIR/Implementation/DrawingBoardScene.cpp \
           $$PROJECT_DIR/Implementation/DrawingPen.cpp \
           $$PROJECT_DIR/Implementation/HandwritingRecognition.cpp \
           $$PROJECT_DIR/Implementation/Matrix.cpp \
           $$PROJECT_DIR/Implementation/NeuralNetwork.cpp \
		   
HEADERS += $$PROJECT_DIR/Implementation/DrawingBoardScene.hpp \
           $$PROJECT_DIR/Implementation/DrawingPen.hpp \
		   $$PROJECT_DIR/Implementation/HandwritingRecognition.hpp \
		   $$PROJECT_DIR/Implementation/Matrix.hpp \
		   $$PROJECT_DIR/Implementation/NeuralNetwork.hpp \
		   
DESTDIR = $$PROJECT_DIR/Binaries

FORMS  += $$PROJECT_DIR/Implementation/Forms/HandwritingRecognition.ui \
		   