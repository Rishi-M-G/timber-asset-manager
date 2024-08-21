#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // My Additions

    // Populating image list from corresponding graphics folder
    populateImageList();

    // Connection for Image Preview
    scene = new QGraphicsScene(this);
    ui->imagePreview->setScene(scene);
    ui->imagePreview->setAlignment(Qt::AlignCenter);
    connect(ui->backgroundList,&QListWidget::itemClicked,this,[this](QListWidgetItem* item) {
        QString fullPath = "C:/Users/Admin/source/repos/Timber/graphics/"+item->text();
        updateImagePreview(fullPath);
    });

    // Adding an item
    connect(ui->btnAddItem, &QPushButton::clicked, this,&MainWindow::handleAddItem);
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

void MainWindow::handleAddItem(){
    // Open file dialog to select an asset
    QString selectedFilter;
    QString filePath = QFileDialog::getOpenFileName (this,tr("Select File"),"",tr("Image Files (*.png *.jpg *.jpeg);;Audio Files (*.mp3 *.wav);;Font Files(*.ttf);;All Files(*)"),&selectedFilter);
    if(filePath.isEmpty())
        return; // User Cancelled or no file selected

    // Determine the target Directory based on the currently active tab and subtab
    QString targetDirectory;
    int currentTabIndex = ui->MaintabWidget->currentIndex();

    // Graphics Tab
    if(currentTabIndex == ui->MaintabWidget->indexOf(ui->graphicsTab)){
        int subTabIndex = ui->graphicSubTabs->currentIndex();
        switch(subTabIndex){
        case 0: // Background
            targetDirectory = "C:/Users/Admin/source/repos/Timber/graphics";
            break;
        case 1: // Player
            targetDirectory = "C:/Users/Admin/source/repos/Timber/graphics";
            break;
        // Will add other tabs later
        }
    }
    // Audio Tab
    else if (currentTabIndex == ui->MaintabWidget->indexOf(ui->audioTab)){
        targetDirectory = "C:/Users/Admin/source/repos/Timber/Sound";
    }
    // Fonts Tab
    else if (currentTabIndex == ui->MaintabWidget->indexOf(ui->fontTab)){
        targetDirectory = "C:/Users/Admin/source/repos/Timber/Fonts";
    }

    // Constructing the target file path
    QFileInfo fileInfo(filePath);
    QString targetFilePath = targetDirectory + "/" + fileInfo.fileName();

    // Copy the file to the target directory
    if(QFile::copy(filePath,targetFilePath)){
        ui->addItemStatus->setText("File Added");
        populateImageList();
    }else{
        ui->addItemStatus->setText("Failed");
        QMessageBox::warning(this, "Error", "Failed to add file to the directory.");
    }
}
// ***********


MainWindow::~MainWindow()
{
    delete ui;
}
