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
    QListWidget *playerList;
    QWidget *cloudTab;
    QListWidget *cloudList;
    QWidget *beeTab;
    QListWidget *beeList;
    QWidget *treeTab;
    QListWidget *treeList;
    QWidget *branchTab;
    QListWidget *branchList;
    QWidget *logTab;
    QListWidget *logList;
    QWidget *gravestoneTab;
    QListWidget *ripList;
    QWidget *audioTab;
    QTabWidget *audioSubTabs;
    QWidget *chopTab;
    QListWidget *chopList;
    QWidget *deathTab;
    QListWidget *deathList;
    QWidget *ootTab;
    QListWidget *ootList;
    QWidget *fontTab;
    QTabWidget *fontSubTabs;
    QWidget *hudTab;
    QListWidget *hudList;
    QWidget *scoreTab;
    QListWidget *scoreList;
    QWidget *messageTab;
    QListWidget *messageList;
    QPushButton *btnAddItem;
    QLabel *addItemStatus;
    QPushButton *btnRemoveItem;
    QPushButton *btnSetAsCurrent;
    QWidget *previewPane;
    QGraphicsView *imagePreview;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(874, 436);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: #2E3440; /* Dark background */\n"
"    color: #ECEFF4; /* Light text color */\n"
"    font-family: \"Segoe UI\", Arial, sans-serif;\n"
"    font-size: 12pt;\n"
"}"));
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
"    border: 1px solid #888888;  /* Softer grey border */\n"
"    background-color: #F0F4F6;  /* Slightly lighter background */\n"
"    border-radius: 8px;  /* Increased border radius for smoother corners */\n"
"}\n"
"\n"
"QWidget:hover {\n"
"    border: 2px solid #6A87D4;  /* Refined hover border color */\n"
"}\n"
""));
        MaintabWidget = new QTabWidget(contentBox);
        MaintabWidget->setObjectName("MaintabWidget");
        MaintabWidget->setGeometry(QRect(10, 10, 541, 241));
        MaintabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab {\n"
"    color: #2C2C2C;  /* Darker gray text color */\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #F5F5F5, stop: 0.4 #EEEEEE,\n"
"                                 stop: 0.5 #E0E0E0, stop: 1.0 #D6D6D6);  /* Slightly brighter gradient */\n"
"    border: 1px solid #B3B3B3;\n"
"    border-bottom-color: #D6D6D6;  /* Matches the pane color */\n"
"    border-top-left-radius: 6px;\n"
"    border-top-right-radius: 6px;\n"
"    min-width: 10ex;  /* Increases tab width slightly */\n"
"    padding: 4px 8px;  /* Adds more padding for a spacious look */\n"
"}\n"
"\n"
"QTabBar::tab:selected, QTabBar::tab:hover {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #FFFFFF, stop: 0.4 #F7F7F7,\n"
"                                 stop: 0.5 #EDEDED, stop: 1.0 #FFFFFF);  /* A lighter gradient for selected and hover state */\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    border-color: #8A8A8A;\n"
""
                        "    border-bottom-color: #D6D6D6;  /* Matches the pane color */\n"
"}\n"
"\n"
"QTabBar::tab:!selected {\n"
"    margin-top: 3px;  /* Adds more spacing for non-selected tabs */\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    border: 1px solid #B3B3B3;\n"
"    background-color: #FFFFFF;  /* A clean white background for the content area */\n"
"    border-radius: 4px;  /* Adds rounded corners to the content area */\n"
"    margin-top: -1px;  /* Ensures seamless connection between tabs and pane */\n"
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
        playerList = new QListWidget(playerTab);
        playerList->setObjectName("playerList");
        playerList->setGeometry(QRect(0, 0, 541, 192));
        graphicSubTabs->addTab(playerTab, QString());
        cloudTab = new QWidget();
        cloudTab->setObjectName("cloudTab");
        cloudList = new QListWidget(cloudTab);
        cloudList->setObjectName("cloudList");
        cloudList->setGeometry(QRect(0, 0, 541, 192));
        graphicSubTabs->addTab(cloudTab, QString());
        beeTab = new QWidget();
        beeTab->setObjectName("beeTab");
        beeList = new QListWidget(beeTab);
        beeList->setObjectName("beeList");
        beeList->setGeometry(QRect(0, 0, 541, 192));
        graphicSubTabs->addTab(beeTab, QString());
        treeTab = new QWidget();
        treeTab->setObjectName("treeTab");
        treeList = new QListWidget(treeTab);
        treeList->setObjectName("treeList");
        treeList->setGeometry(QRect(0, 0, 541, 192));
        graphicSubTabs->addTab(treeTab, QString());
        branchTab = new QWidget();
        branchTab->setObjectName("branchTab");
        branchList = new QListWidget(branchTab);
        branchList->setObjectName("branchList");
        branchList->setGeometry(QRect(0, 0, 541, 192));
        graphicSubTabs->addTab(branchTab, QString());
        logTab = new QWidget();
        logTab->setObjectName("logTab");
        logList = new QListWidget(logTab);
        logList->setObjectName("logList");
        logList->setGeometry(QRect(0, 0, 541, 192));
        graphicSubTabs->addTab(logTab, QString());
        gravestoneTab = new QWidget();
        gravestoneTab->setObjectName("gravestoneTab");
        ripList = new QListWidget(gravestoneTab);
        ripList->setObjectName("ripList");
        ripList->setGeometry(QRect(0, 0, 541, 192));
        graphicSubTabs->addTab(gravestoneTab, QString());
        MaintabWidget->addTab(graphicsTab, QString());
        audioTab = new QWidget();
        audioTab->setObjectName("audioTab");
        audioSubTabs = new QTabWidget(audioTab);
        audioSubTabs->setObjectName("audioSubTabs");
        audioSubTabs->setGeometry(QRect(0, 0, 541, 221));
        chopTab = new QWidget();
        chopTab->setObjectName("chopTab");
        chopList = new QListWidget(chopTab);
        chopList->setObjectName("chopList");
        chopList->setGeometry(QRect(0, 0, 541, 192));
        audioSubTabs->addTab(chopTab, QString());
        deathTab = new QWidget();
        deathTab->setObjectName("deathTab");
        deathList = new QListWidget(deathTab);
        deathList->setObjectName("deathList");
        deathList->setGeometry(QRect(0, 0, 541, 192));
        audioSubTabs->addTab(deathTab, QString());
        ootTab = new QWidget();
        ootTab->setObjectName("ootTab");
        ootList = new QListWidget(ootTab);
        ootList->setObjectName("ootList");
        ootList->setGeometry(QRect(0, 0, 541, 192));
        audioSubTabs->addTab(ootTab, QString());
        MaintabWidget->addTab(audioTab, QString());
        fontTab = new QWidget();
        fontTab->setObjectName("fontTab");
        fontSubTabs = new QTabWidget(fontTab);
        fontSubTabs->setObjectName("fontSubTabs");
        fontSubTabs->setGeometry(QRect(0, 0, 541, 221));
        hudTab = new QWidget();
        hudTab->setObjectName("hudTab");
        hudList = new QListWidget(hudTab);
        hudList->setObjectName("hudList");
        hudList->setGeometry(QRect(0, 0, 541, 192));
        fontSubTabs->addTab(hudTab, QString());
        scoreTab = new QWidget();
        scoreTab->setObjectName("scoreTab");
        scoreList = new QListWidget(scoreTab);
        scoreList->setObjectName("scoreList");
        scoreList->setGeometry(QRect(0, 0, 541, 192));
        fontSubTabs->addTab(scoreTab, QString());
        messageTab = new QWidget();
        messageTab->setObjectName("messageTab");
        messageList = new QListWidget(messageTab);
        messageList->setObjectName("messageList");
        messageList->setGeometry(QRect(0, 0, 541, 192));
        fontSubTabs->addTab(messageTab, QString());
        MaintabWidget->addTab(fontTab, QString());
        btnAddItem = new QPushButton(contentBox);
        btnAddItem->setObjectName("btnAddItem");
        btnAddItem->setGeometry(QRect(450, 310, 80, 24));
        btnAddItem->setStyleSheet(QString::fromUtf8("QPushButton#btnAddItem {\n"
"    background-color: #4CAF50;  /* Green background */\n"
"    color: white;  /* White text */\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    padding: 4px 10px;\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size: 10pt;\n"
"    transition: background-color 0.3s ease;  /* Smooth transition for background color */\n"
"}\n"
"\n"
"QPushButton#btnAddItem:hover {\n"
"    background-color: #45A049;  /* Darker green on hover */\n"
"}\n"
"\n"
"QPushButton#btnAddItem:pressed {\n"
"    background-color: #3E8E41;  /* Even darker green when pressed */\n"
"}\n"
"\n"
"QPushButton#btnAddItem:disabled {\n"
"    background-color: #CCCCCC;  /* Light gray background when disabled */\n"
"    color: #666666;  /* Darker gray text */\n"
"}\n"
""));
        addItemStatus = new QLabel(contentBox);
        addItemStatus->setObjectName("addItemStatus");
        addItemStatus->setGeometry(QRect(340, 310, 91, 21));
        addItemStatus->setStyleSheet(QString::fromUtf8("QLabel#addItemStatus {\n"
"    background-color: #F0F4F6;    /* Light blue background indicating information */\n"
"    color: #1A73E8;               /* Google blue text color for readability */\n"
"    border: none;\n"
"    border-radius: 4px;           /* Slightly rounded corners */\n"
"    padding: 4px 10px;            /* Adequate padding for text */\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"QLabel#addItemStatus[status=\"success\"] {\n"
"    background-color: #E6F4EA;\n"
"    color: #34A853;\n"
"    border: 1px solid #34A853;\n"
"}\n"
"\n"
"QLabel#addItemStatus[status=\"error\"] {\n"
"    background-color: #FDECEA;\n"
"    color: #D93025;\n"
"    border: 1px solid #D93025;\n"
"}\n"
"\n"
"QLabel#addItemStatus:empty {\n"
"    border: none;  /* Remove border when label is empty */\n"
"    background-color: transparent;  /* Remove background color when empty */\n"
"}"));
        btnRemoveItem = new QPushButton(contentBox);
        btnRemoveItem->setObjectName("btnRemoveItem");
        btnRemoveItem->setGeometry(QRect(450, 340, 80, 24));
        btnRemoveItem->setStyleSheet(QString::fromUtf8("QPushButton#btnRemoveItem {\n"
"    background-color: #F44336;  /* Red background */\n"
"    color: white;  /* White text */\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    padding: 3px 8px;\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size: 8pt;\n"
"    transition: background-color 0.3s ease;  /* Smooth transition for background color */\n"
"}\n"
"\n"
"QPushButton#btnRemoveItem:hover {\n"
"    background-color: #E53935;  /* Darker red on hover */\n"
"}\n"
"\n"
"QPushButton#btnRemoveItem:pressed {\n"
"    background-color: #D32F2F;  /* Even darker red when pressed */\n"
"}\n"
"\n"
"QPushButton#btnRemoveItem:disabled {\n"
"    background-color: #CCCCCC;  /* Light gray background when disabled */\n"
"    color: #666666;  /* Darker gray text */\n"
"}\n"
""));
        btnSetAsCurrent = new QPushButton(contentBox);
        btnSetAsCurrent->setObjectName("btnSetAsCurrent");
        btnSetAsCurrent->setGeometry(QRect(320, 310, 111, 24));
        btnSetAsCurrent->setStyleSheet(QString::fromUtf8("QPushButton#btnSetAsCurrent {\n"
"    background-color: #4CAF50;  /* Green background */\n"
"    color: white;  /* White text */\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    padding: 3px 8px;\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size: 8pt;\n"
"    transition: background-color 0.3s ease;  /* Smooth transition for background color */\n"
"}\n"
"\n"
"QPushButton#btnSetAsCurrent:hover {\n"
"    background-color: #43A047;  /* Darker green on hover */\n"
"}\n"
"\n"
"QPushButton#btnSetAsCurrent:pressed {\n"
"    background-color: #388E3C;  /* Even darker green when pressed */\n"
"}\n"
"\n"
"QPushButton#btnSetAsCurrent:disabled {\n"
"    background-color: #CCCCCC;  /* Light gray background when disabled */\n"
"    color: #666666;  /* Darker gray text */\n"
"}\n"
""));

        horizontalLayout_4->addWidget(contentBox);

        previewPane = new QWidget(centrawidget);
        previewPane->setObjectName("previewPane");
        sizePolicy.setHeightForWidth(previewPane->sizePolicy().hasHeightForWidth());
        previewPane->setSizePolicy(sizePolicy);
        previewPane->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    border: 1px solid #333333;  /* Dark grey border for a more sophisticated look */\n"
"    background-color: #F4F4F4;  /* Soft, neutral background color */\n"
"    border-radius: 8px;  /* Slightly larger radius for a smoother appearance */\n"
"    box-shadow: 0px 4px 6px rgba(0, 0, 0, 0.1);  /* Subtle shadow for depth */\n"
"}\n"
"\n"
"QWidget:hover {\n"
"    border: 1px solid #1E90FF;  /* Gentle blue border on hover */\n"
"    background-color: #FFFFFF;  /* Pure white background on hover for contrast */\n"
"}\n"
""));
        imagePreview = new QGraphicsView(previewPane);
        imagePreview->setObjectName("imagePreview");
        imagePreview->setGeometry(QRect(10, 10, 256, 261));
        imagePreview->setStyleSheet(QString::fromUtf8("QGraphicsView {\n"
"    border: 2px solid #2E3A46;  /* Dark slate grey border for a modern look */\n"
"    background-color: #F8F9FA;  /* Very light grey background */\n"
"    border-radius: 10px;  /* Smooth, rounded corners */\n"
"    padding: 5px;  /* Adds a slight padding inside the border */\n"
"    box-shadow: 0px 4px 8px rgba(0, 0, 0, 0.15);  /* Subtle shadow for a professional depth */\n"
"}\n"
"\n"
"QGraphicsView:hover {\n"
"    border: 2px solid #1C6EA4;  /* Calming blue border on hover */\n"
"    background-color: #FFFFFF;  /* Crisp white background on hover */\n"
"}\n"
""));

        horizontalLayout_4->addWidget(previewPane);

        horizontalLayout_4->setStretch(0, 2);
        horizontalLayout_4->setStretch(1, 1);

        horizontalLayout_5->addLayout(horizontalLayout_4);

        MainWindow->setCentralWidget(centrawidget);

        retranslateUi(MainWindow);

        MaintabWidget->setCurrentIndex(0);
        graphicSubTabs->setCurrentIndex(0);
        audioSubTabs->setCurrentIndex(2);
        fontSubTabs->setCurrentIndex(2);


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
        audioSubTabs->setTabText(audioSubTabs->indexOf(chopTab), QCoreApplication::translate("MainWindow", "Chop", nullptr));
        audioSubTabs->setTabText(audioSubTabs->indexOf(deathTab), QCoreApplication::translate("MainWindow", "Death", nullptr));
        audioSubTabs->setTabText(audioSubTabs->indexOf(ootTab), QCoreApplication::translate("MainWindow", "Out Of Time", nullptr));
        MaintabWidget->setTabText(MaintabWidget->indexOf(audioTab), QCoreApplication::translate("MainWindow", "Audio", nullptr));
        fontSubTabs->setTabText(fontSubTabs->indexOf(hudTab), QCoreApplication::translate("MainWindow", "Heads Up Display", nullptr));
        fontSubTabs->setTabText(fontSubTabs->indexOf(scoreTab), QCoreApplication::translate("MainWindow", "Score", nullptr));
        fontSubTabs->setTabText(fontSubTabs->indexOf(messageTab), QCoreApplication::translate("MainWindow", "Message", nullptr));
        MaintabWidget->setTabText(MaintabWidget->indexOf(fontTab), QCoreApplication::translate("MainWindow", "Font", nullptr));
        btnAddItem->setText(QCoreApplication::translate("MainWindow", "Add Item", nullptr));
        addItemStatus->setText(QString());
        btnRemoveItem->setText(QCoreApplication::translate("MainWindow", "Remove Item", nullptr));
        btnSetAsCurrent->setText(QCoreApplication::translate("MainWindow", "Set As Current", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
