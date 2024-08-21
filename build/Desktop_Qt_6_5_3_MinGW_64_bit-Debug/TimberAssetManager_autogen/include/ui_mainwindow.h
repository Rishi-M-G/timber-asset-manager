/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centrawidget;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QWidget *contentBox;
    QTabWidget *MaintabWidget;
    QWidget *graphicsTab;
    QTabWidget *graphicSubTabs;
    QWidget *backgroundTab;
    QListWidget *backgroundList;
    QWidget *playerTab;
    QWidget *cloudTab;
    QWidget *beeTab;
    QWidget *treeTab;
    QWidget *branchTab;
    QWidget *logTab;
    QWidget *gravestoneTab;
    QWidget *audioTab;
    QWidget *fontTab;
    QPushButton *btnAddItem;
    QLabel *addItemStatus;
    QWidget *previewPane;
    QGraphicsView *imagePreview;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(874, 436);
        centrawidget = new QWidget(MainWindow);
        centrawidget->setObjectName("centrawidget");
        horizontalLayout_5 = new QHBoxLayout(centrawidget);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        contentBox = new QWidget(centrawidget);
        contentBox->setObjectName("contentBox");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(contentBox->sizePolicy().hasHeightForWidth());
        contentBox->setSizePolicy(sizePolicy);
        contentBox->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    border: 1px solid #000000;  /* Black border */\n"
"    background-color: #E4F6F8;  /* Pale grey background */\n"
"	border-radius: 5px;\n"
"}\n"
"QWidget:hover {\n"
"    border: 2px solid #a2a2d0;  /* Changes border color on hover */\n"
"}"));
        MaintabWidget = new QTabWidget(contentBox);
        MaintabWidget->setObjectName("MaintabWidget");
        MaintabWidget->setGeometry(QRect(10, 10, 541, 241));
        MaintabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::tab-bar {\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"	color: #333333; /* Dark gray text color */\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                 stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"    border: 1px solid #C4C4C3;\n"
"    border-bottom-color: #C2C7CB; /* same as the pane color */\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"    min-width: 8ex;\n"
"    padding: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:selected, QTabBar::tab:hover {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #fafafa, stop: 0.4 #f4f4f4,\n"
"                                 stop: 0.5 #e7e7e7, stop: 1.0 #fafafa);\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    border-color: #9B9B9B;\n"
"    border-bottom-color: #C2C7CB; /* same as pane color */\n"
"}\n"
"\n"
"QTabBar::tab:!selected {\n"
"    margin-top: 2px; /* make non-selecte"
                        "d tabs look smaller */\n"
"}\n"
"\n"
"\n"
"QTabWidget::pane {\n"
"    border: 0.5px #C4C4C3;\n"
"    background-color: #F8F8F8; /* Sets background color of the content area */\n"
"}\n"
""));
        graphicsTab = new QWidget();
        graphicsTab->setObjectName("graphicsTab");
        graphicSubTabs = new QTabWidget(graphicsTab);
        graphicSubTabs->setObjectName("graphicSubTabs");
        graphicSubTabs->setGeometry(QRect(0, 0, 541, 221));
        graphicSubTabs->setStyleSheet(QString::fromUtf8("QTabWidget::pane {\n"
"    border: none;\n"
"    background-color: #F8F8F8; /* Sets background color of the content area */\n"
"}"));
        backgroundTab = new QWidget();
        backgroundTab->setObjectName("backgroundTab");
        backgroundList = new QListWidget(backgroundTab);
        backgroundList->setObjectName("backgroundList");
        backgroundList->setGeometry(QRect(-5, 0, 551, 191));
        graphicSubTabs->addTab(backgroundTab, QString());
        playerTab = new QWidget();
        playerTab->setObjectName("playerTab");
        graphicSubTabs->addTab(playerTab, QString());
        cloudTab = new QWidget();
        cloudTab->setObjectName("cloudTab");
        graphicSubTabs->addTab(cloudTab, QString());
        beeTab = new QWidget();
        beeTab->setObjectName("beeTab");
        graphicSubTabs->addTab(beeTab, QString());
        treeTab = new QWidget();
        treeTab->setObjectName("treeTab");
        graphicSubTabs->addTab(treeTab, QString());
        branchTab = new QWidget();
        branchTab->setObjectName("branchTab");
        graphicSubTabs->addTab(branchTab, QString());
        logTab = new QWidget();
        logTab->setObjectName("logTab");
        graphicSubTabs->addTab(logTab, QString());
        gravestoneTab = new QWidget();
        gravestoneTab->setObjectName("gravestoneTab");
        graphicSubTabs->addTab(gravestoneTab, QString());
        MaintabWidget->addTab(graphicsTab, QString());
        audioTab = new QWidget();
        audioTab->setObjectName("audioTab");
        MaintabWidget->addTab(audioTab, QString());
        fontTab = new QWidget();
        fontTab->setObjectName("fontTab");
        MaintabWidget->addTab(fontTab, QString());
        btnAddItem = new QPushButton(contentBox);
        btnAddItem->setObjectName("btnAddItem");
        btnAddItem->setGeometry(QRect(450, 310, 80, 24));
        addItemStatus = new QLabel(contentBox);
        addItemStatus->setObjectName("addItemStatus");
        addItemStatus->setGeometry(QRect(340, 310, 91, 21));

        horizontalLayout_4->addWidget(contentBox);

        previewPane = new QWidget(centrawidget);
        previewPane->setObjectName("previewPane");
        sizePolicy.setHeightForWidth(previewPane->sizePolicy().hasHeightForWidth());
        previewPane->setSizePolicy(sizePolicy);
        previewPane->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    border: 1px solid #000000;  /* Black border */\n"
"    background-color: #E4F6F8;  /* Pale grey background */\n"
"	border-radius: 5px;\n"
"}\n"
"QWidget:hover {\n"
"    border: 2px solid red;  /* Changes border color on hover */\n"
"}"));
        imagePreview = new QGraphicsView(previewPane);
        imagePreview->setObjectName("imagePreview");
        imagePreview->setGeometry(QRect(10, 10, 256, 261));

        horizontalLayout_4->addWidget(previewPane);

        horizontalLayout_4->setStretch(0, 2);
        horizontalLayout_4->setStretch(1, 1);

        horizontalLayout_5->addLayout(horizontalLayout_4);

        MainWindow->setCentralWidget(centrawidget);

        retranslateUi(MainWindow);

        MaintabWidget->setCurrentIndex(2);
        graphicSubTabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Asset Management Tool - Timber", nullptr));
        graphicSubTabs->setTabText(graphicSubTabs->indexOf(backgroundTab), QCoreApplication::translate("MainWindow", "Background", nullptr));
        graphicSubTabs->setTabText(graphicSubTabs->indexOf(playerTab), QCoreApplication::translate("MainWindow", "Player", nullptr));
        graphicSubTabs->setTabText(graphicSubTabs->indexOf(cloudTab), QCoreApplication::translate("MainWindow", "Cloud", nullptr));
        graphicSubTabs->setTabText(graphicSubTabs->indexOf(beeTab), QCoreApplication::translate("MainWindow", "Bee", nullptr));
        graphicSubTabs->setTabText(graphicSubTabs->indexOf(treeTab), QCoreApplication::translate("MainWindow", "Tree", nullptr));
        graphicSubTabs->setTabText(graphicSubTabs->indexOf(branchTab), QCoreApplication::translate("MainWindow", "Branch", nullptr));
        graphicSubTabs->setTabText(graphicSubTabs->indexOf(logTab), QCoreApplication::translate("MainWindow", "Log", nullptr));
        graphicSubTabs->setTabText(graphicSubTabs->indexOf(gravestoneTab), QCoreApplication::translate("MainWindow", "Grave Stone", nullptr));
        MaintabWidget->setTabText(MaintabWidget->indexOf(graphicsTab), QCoreApplication::translate("MainWindow", "Graphics", nullptr));
        MaintabWidget->setTabText(MaintabWidget->indexOf(audioTab), QCoreApplication::translate("MainWindow", "Audio", nullptr));
        MaintabWidget->setTabText(MaintabWidget->indexOf(fontTab), QCoreApplication::translate("MainWindow", "Font", nullptr));
        btnAddItem->setText(QCoreApplication::translate("MainWindow", "Add Item", nullptr));
        addItemStatus->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
