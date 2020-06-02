/********************************************************************************
** Form generated from reading UI file 'HandwritingRecognition.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HANDWRITINGRECOGNITION_H
#define UI_HANDWRITINGRECOGNITION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HandwritingRecognition
{
public:
    QAction *actionOpen_;
    QAction *actionSave_;
    QAction *actionSaveAs_;
    QAction *actionQuit_;
    QAction *actionOpenSettings_;
    QAction *actionConnection_Via_UART;
    QAction *actionConnection_via_Ethernet;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGraphicsView *drawingBoardView_;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QDoubleSpinBox *learninRateSpinBox_;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QDoubleSpinBox *dropRateSpinBox_;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QPushButton *clearBoardButton_;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *correctAnswer_;
    QLabel *confidenceOf_;
    QPushButton *correctMe_;
    QSpacerItem *horizontalSpacer;
    QPushButton *train_;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QProgressBar *trainingProgress_;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QSpinBox *epoch_;
    QListWidget *listWidget;
    QStatusBar *statusbar_;
    QToolBar *toolBar_;

    void setupUi(QMainWindow *HandwritingRecognition)
    {
        if (HandwritingRecognition->objectName().isEmpty())
            HandwritingRecognition->setObjectName(QStringLiteral("HandwritingRecognition"));
        HandwritingRecognition->resize(276, 688);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HandwritingRecognition->sizePolicy().hasHeightForWidth());
        HandwritingRecognition->setSizePolicy(sizePolicy);
        HandwritingRecognition->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"   background-color:#d0d0d0;\n"
"};\n"
"\n"
"QTextBrowser\n"
"{\n"
"    color: black;\n"
"  background-color: white;\n"
"border :0px;\n"
"}\n"
"\n"
"\n"
"QTabBar::tab \n"
"{\n"
"    color: #b1b1b1;\n"
"    border: 1px solid #444;\n"
"    background-color: grey;\n"
"    padding-left: 10px;\n"
"    padding-right: 10px;\n"
"    padding-top: 5px;\n"
"    padding-bottom: 3px;\n"
"    margin-right: -1px;\n"
"}\n"
"\n"
"QTabWidget::pane\n"
" {\n"
"    border: 0px solid #444;\n"
"    top: 1px;\n"
"}\n"
"\n"
"QTabBar::tab:last\n"
"{\n"
"    margin-right: 0; /* the last selected tab has nothing to overlap with on the right */\n"
"    border-top-right-radius: 8px;\n"
"    background-color:grey;\n"
"}\n"
"\n"
"QTabBar::tab:first:!selected\n"
"{\n"
"    margin-left: 1px; /* the last selected tab has nothing to overlap with on the right */\n"
"\n"
"     border-top-left-radius: 1px;\n"
"     border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"}\n"
"\n"
"QTabBar::tab:!selected\n"
"{\n"
"  "
                        "  border-color: #f8f8f8;\n"
"    border-bottom-color: #C2C7CB; /* same as pane color */\n"
"    background-color:#f8f8f8;\n"
"    color:grey;\n"
"    border-top-left-radius: 1px;\n"
"    border-top-right-radius: 15px;\n"
"   border-bottom-right-radius: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:selected\n"
"{\n"
"    border-top-left-radius: 1px;\n"
"    border-top-right-radius: 10px;\n"
"    margin-bottom: 0px;\n"
"    background-colr: grey;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    border-color: #9B9B9B;\n"
"    border-bottom-color: #C2C7CB; /* same as pane color */\n"
"    background-color:#e3e3e3;\n"
"    color:black;\n"
"    border-top-left-radius: 15px;\n"
"    border-top-right-radius: 15px;\n"
"   border-bottom-right-radius: 2px;\n"
"}\n"
"\n"
"\n"
"QTabBar::tab:!selected:hover\n"
"{\n"
"    /*border-top: 2px solid #ffaa00;\n"
"    padding-bottom: 3px;*/\n"
"    border-top-left-radius: 1px;\n"
"    border-top-right-radius: 8px;\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:1 #9B9B9B, "
                        "stop:0.4 #e3e3e3, stop:0.2 #e3e3e3, stop:0.1 #ffaa00);\n"
"}\n"
"\n"
"QTabBar::close-button \n"
"{\n"
"    image: url(:newPrefix/close.png);\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: right; \n"
"    width: 5px;\n"
"    height: 5px;\n"
"}\n"
"\n"
"QTreeWidget\n"
"{\n"
"   border : 1px solid #9B9B9B;\n"
"   border-radius : 15px;\n"
"   background-color: white;\n"
"};"));
        actionOpen_ = new QAction(HandwritingRecognition);
        actionOpen_->setObjectName(QStringLiteral("actionOpen_"));
        actionSave_ = new QAction(HandwritingRecognition);
        actionSave_->setObjectName(QStringLiteral("actionSave_"));
        actionSaveAs_ = new QAction(HandwritingRecognition);
        actionSaveAs_->setObjectName(QStringLiteral("actionSaveAs_"));
        actionQuit_ = new QAction(HandwritingRecognition);
        actionQuit_->setObjectName(QStringLiteral("actionQuit_"));
        actionOpenSettings_ = new QAction(HandwritingRecognition);
        actionOpenSettings_->setObjectName(QStringLiteral("actionOpenSettings_"));
        actionConnection_Via_UART = new QAction(HandwritingRecognition);
        actionConnection_Via_UART->setObjectName(QStringLiteral("actionConnection_Via_UART"));
        actionConnection_Via_UART->setCheckable(true);
        actionConnection_via_Ethernet = new QAction(HandwritingRecognition);
        actionConnection_via_Ethernet->setObjectName(QStringLiteral("actionConnection_via_Ethernet"));
        actionConnection_via_Ethernet->setCheckable(true);
        centralwidget = new QWidget(HandwritingRecognition);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        drawingBoardView_ = new QGraphicsView(centralwidget);
        drawingBoardView_->setObjectName(QStringLiteral("drawingBoardView_"));
        drawingBoardView_->setStyleSheet(QLatin1String("QGraphicsView\n"
"{\n"
"   color:black;\n"
"   background-color :white;\n"
"};"));
        drawingBoardView_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        drawingBoardView_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(drawingBoardView_, 0, 0, 1, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_4->addWidget(label_5);

        learninRateSpinBox_ = new QDoubleSpinBox(centralwidget);
        learninRateSpinBox_->setObjectName(QStringLiteral("learninRateSpinBox_"));
        learninRateSpinBox_->setDecimals(4);
        learninRateSpinBox_->setMinimum(0.001);
        learninRateSpinBox_->setMaximum(1);
        learninRateSpinBox_->setSingleStep(0.001);
        learninRateSpinBox_->setValue(0.1);

        horizontalLayout_4->addWidget(learninRateSpinBox_);


        gridLayout->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        dropRateSpinBox_ = new QDoubleSpinBox(centralwidget);
        dropRateSpinBox_->setObjectName(QStringLiteral("dropRateSpinBox_"));
        dropRateSpinBox_->setDecimals(4);
        dropRateSpinBox_->setMaximum(0.5);
        dropRateSpinBox_->setSingleStep(0.0001);
        dropRateSpinBox_->setValue(0.2);

        horizontalLayout_5->addWidget(dropRateSpinBox_);


        gridLayout->addLayout(horizontalLayout_5, 1, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setWordWrap(true);

        verticalLayout_3->addWidget(label);

        clearBoardButton_ = new QPushButton(centralwidget);
        clearBoardButton_->setObjectName(QStringLiteral("clearBoardButton_"));

        verticalLayout_3->addWidget(clearBoardButton_);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        correctAnswer_ = new QLineEdit(centralwidget);
        correctAnswer_->setObjectName(QStringLiteral("correctAnswer_"));
        correctAnswer_->setMaximumSize(QSize(80, 16777215));
        QFont font;
        font.setPointSize(24);
        correctAnswer_->setFont(font);

        horizontalLayout_3->addWidget(correctAnswer_);

        confidenceOf_ = new QLabel(centralwidget);
        confidenceOf_->setObjectName(QStringLiteral("confidenceOf_"));
        confidenceOf_->setWordWrap(true);

        horizontalLayout_3->addWidget(confidenceOf_);

        correctMe_ = new QPushButton(centralwidget);
        correctMe_->setObjectName(QStringLiteral("correctMe_"));
        correctMe_->setMinimumSize(QSize(0, 40));

        horizontalLayout_3->addWidget(correctMe_);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_3);

        train_ = new QPushButton(centralwidget);
        train_->setObjectName(QStringLiteral("train_"));

        verticalLayout_2->addWidget(train_);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        trainingProgress_ = new QProgressBar(centralwidget);
        trainingProgress_->setObjectName(QStringLiteral("trainingProgress_"));
        trainingProgress_->setValue(0);

        horizontalLayout_2->addWidget(trainingProgress_);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        epoch_ = new QSpinBox(centralwidget);
        epoch_->setObjectName(QStringLiteral("epoch_"));
        epoch_->setMaximum(5555555);
        epoch_->setValue(20);

        horizontalLayout->addWidget(epoch_);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        gridLayout->addLayout(verticalLayout_3, 2, 0, 1, 2);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout->addWidget(listWidget, 3, 0, 1, 2);

        HandwritingRecognition->setCentralWidget(centralwidget);
        statusbar_ = new QStatusBar(HandwritingRecognition);
        statusbar_->setObjectName(QStringLiteral("statusbar_"));
        HandwritingRecognition->setStatusBar(statusbar_);
        toolBar_ = new QToolBar(HandwritingRecognition);
        toolBar_->setObjectName(QStringLiteral("toolBar_"));
        toolBar_->setMinimumSize(QSize(0, 0));
        toolBar_->setMaximumSize(QSize(16777215, 20));
        toolBar_->setIconSize(QSize(16, 16));
        HandwritingRecognition->addToolBar(Qt::TopToolBarArea, toolBar_);

        retranslateUi(HandwritingRecognition);

        QMetaObject::connectSlotsByName(HandwritingRecognition);
    } // setupUi

    void retranslateUi(QMainWindow *HandwritingRecognition)
    {
        HandwritingRecognition->setWindowTitle(QApplication::translate("HandwritingRecognition", "Handwritten Number Recognition", Q_NULLPTR));
        actionOpen_->setText(QApplication::translate("HandwritingRecognition", "Open", Q_NULLPTR));
        actionSave_->setText(QApplication::translate("HandwritingRecognition", "Save", Q_NULLPTR));
        actionSaveAs_->setText(QApplication::translate("HandwritingRecognition", "Save As", Q_NULLPTR));
        actionQuit_->setText(QApplication::translate("HandwritingRecognition", "Quit", Q_NULLPTR));
        actionOpenSettings_->setText(QApplication::translate("HandwritingRecognition", "Open Uart Settings", Q_NULLPTR));
        actionConnection_Via_UART->setText(QApplication::translate("HandwritingRecognition", "Connection via UART", Q_NULLPTR));
        actionConnection_via_Ethernet->setText(QApplication::translate("HandwritingRecognition", "Connection via Ethernet", Q_NULLPTR));
        label_5->setText(QApplication::translate("HandwritingRecognition", "Learning Rate", Q_NULLPTR));
        label_6->setText(QApplication::translate("HandwritingRecognition", "Drop Rate", Q_NULLPTR));
        label->setText(QApplication::translate("HandwritingRecognition", "Using the mouse, Draw an alphabet or anumber from 0 - 9", Q_NULLPTR));
        clearBoardButton_->setText(QApplication::translate("HandwritingRecognition", "Clear Board", Q_NULLPTR));
        label_2->setText(QApplication::translate("HandwritingRecognition", "My Guess", Q_NULLPTR));
        confidenceOf_->setText(QString());
        correctMe_->setText(QApplication::translate("HandwritingRecognition", "Correct Me", Q_NULLPTR));
        train_->setText(QApplication::translate("HandwritingRecognition", "Train", Q_NULLPTR));
        label_3->setText(QApplication::translate("HandwritingRecognition", "Training Progress", Q_NULLPTR));
        label_4->setText(QApplication::translate("HandwritingRecognition", "Epoch", Q_NULLPTR));
        toolBar_->setWindowTitle(QApplication::translate("HandwritingRecognition", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HandwritingRecognition: public Ui_HandwritingRecognition {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANDWRITINGRECOGNITION_H
