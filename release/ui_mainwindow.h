/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *startMotorsButton;
    QTextEdit *filePathTextField;
    QPushButton *browseFilesButton;
    QPushButton *loadFileButton;
    QLabel *label;
    QLabel *cameraImage;
    QLabel *fileAttributesLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1129, 723);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        startMotorsButton = new QPushButton(centralWidget);
        startMotorsButton->setObjectName(QStringLiteral("startMotorsButton"));
        startMotorsButton->setGeometry(QRect(1020, 130, 99, 27));
        filePathTextField = new QTextEdit(centralWidget);
        filePathTextField->setObjectName(QStringLiteral("filePathTextField"));
        filePathTextField->setGeometry(QRect(570, 20, 431, 31));
        browseFilesButton = new QPushButton(centralWidget);
        browseFilesButton->setObjectName(QStringLiteral("browseFilesButton"));
        browseFilesButton->setGeometry(QRect(1000, 20, 21, 31));
        loadFileButton = new QPushButton(centralWidget);
        loadFileButton->setObjectName(QStringLiteral("loadFileButton"));
        loadFileButton->setGeometry(QRect(1020, 20, 99, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(570, 0, 67, 17));
        cameraImage = new QLabel(centralWidget);
        cameraImage->setObjectName(QStringLiteral("cameraImage"));
        cameraImage->setGeometry(QRect(10, 0, 481, 331));
        cameraImage->setAutoFillBackground(false);
        cameraImage->setStyleSheet(QLatin1String("Background-color: #000;\n"
"border-style: outset;\n"
"border-width: 5px;\n"
"border-color: #262626;"));
        cameraImage->setFrameShape(QFrame::StyledPanel);
        cameraImage->setFrameShadow(QFrame::Plain);
        fileAttributesLabel = new QLabel(centralWidget);
        fileAttributesLabel->setObjectName(QStringLiteral("fileAttributesLabel"));
        fileAttributesLabel->setGeometry(QRect(570, 70, 411, 111));
        fileAttributesLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1129, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        startMotorsButton->setText(QApplication::translate("MainWindow", "Start motors", 0));
        browseFilesButton->setText(QApplication::translate("MainWindow", "...", 0));
        loadFileButton->setText(QApplication::translate("MainWindow", "Load", 0));
        label->setText(QApplication::translate("MainWindow", ".csv file", 0));
        cameraImage->setText(QApplication::translate("MainWindow", "Camera image", 0));
        fileAttributesLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
