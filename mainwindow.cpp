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
    ui->imagePreview->setAlignment(Qt::AlignCenter);

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

    // Filtering out only the images
    QStringList filters;
    filters << "*.png" << "*.jpg" << ".jpeg" << ".bmp";


    // Getting the list of files
    QFileInfoList fileList = dir.entryInfoList(filters,QDir::Files | QDir::NoDotAndDotDot);

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

    // Check if image is not null or not
    if(!image.isNull()){
        scene->addPixmap(image); // Adding Image to Scene
        scene->setSceneRect(image.rect()); // Adjusting scene size to image size

    // Deciding whether to fit the image or use a customer scaling factor
    if(image.width() < 500 & image.height() < 500){
        // For smaller images, ensure they are not scaled too much
        ui->imagePreview->resetTransform(); // Reset any previous scalings
        ui->imagePreview->scale(0.8,0.8); // Scaling Factor
    }else {
        ui->imagePreview->fitInView(scene->itemsBoundingRect(),Qt::KeepAspectRatio);
    }
    }else{
        qDebug() << "Failed to load image: "<<imagePath;

    }
}
// ***********


MainWindow::~MainWindow()
{
    delete ui;
}
