#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // My Additions
    populateImageList();

    scene = new QGraphicsScene(this);
    ui->imagePreview->setScene(scene);

    connect(ui->backgroundList,&QListWidget::itemClicked,this,[this](QListWidgetItem* item) {
        QString fullPath = "C:/Users/Admin/source/repos/Timber/graphics/"+item->text();
        updateImagePreview(fullPath);
    });
    //*************
}

// My Additions
// Code to Populate List inside graphics tab
void MainWindow::populateImageList(){
    QString folderPath = "C:/Users/Admin/source/repos/Timber/graphics";
    QDir dir(folderPath);

    // Getting the list of files
    QFileInfoList fileList = dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);

    // Find the list widget by object name
    QListWidget* listWidget = findChild<QListWidget*>("backgroundList");

    if(listWidget){
        listWidget->clear(); // Clear existing items, if any

        foreach(const QFileInfo &file,fileList){
            listWidget->addItem(file.fileName()); // Adding file names to the list
        }
    }

}

void MainWindow::updateImagePreview(const QString &imagePath){
    QPixmap image(imagePath);
    scene->clear(); // Clear Previous items
    scene->addPixmap(image);
    ui->imagePreview->fitInView(scene->itemsBoundingRect(),Qt::KeepAspectRatio);
}
// ***********


MainWindow::~MainWindow()
{
    delete ui;
}
