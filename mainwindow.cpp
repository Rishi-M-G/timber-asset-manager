#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
     * Function Call :  Populating image list from corresponding graphics folder
    */
    populateItemList();

    /*
     * Image Preview
    */
    // Connection for Image Preview
    scene = new QGraphicsScene(this);
    ui->imagePreview->setScene(scene);
    ui->imagePreview->setAlignment(Qt::AlignCenter);

    //connection signals for all relevant QListWidget objects
    QList<QListWidget*> listWidgets = {ui->backgroundList,ui->playerList,ui->cloudList,
                                        ui->beeList,ui->treeList,ui->branchList,
                                        ui->logList,ui->ripList,ui->chopList,
                                        ui->deathList,ui->ootList,ui->hudList,
                                        ui->messageList,ui->scoreList};

    // Iterating through listWidgets
    for(QListWidget* listWidget:listWidgets){
        connect(listWidget,&QListWidget::itemClicked,this,[this,listWidget](QListWidgetItem* item){
            QString baseFolder = "C:/Users/Admin/source/repos/Timber/";
            QString subFolder = listWidget->objectName().replace("List","").toLower();
            QString fullPath;
            if(listWidget == ui->chopList || listWidget == ui->deathList || listWidget == ui->ootList){
                fullPath = baseFolder + "Sound/"+subFolder+"/"+item->text();
            }
            else if(listWidget == ui->hudList || listWidget == ui->messageList || listWidget == ui->scoreList){
                fullPath = baseFolder + "Fonts/"+subFolder+"/"+item->text();
            }
            else{
                fullPath = baseFolder + "graphics/"+subFolder+"/"+item->text();
            }
            updateImagePreview(fullPath);
        });
    }
    /*
     * Adding an item
    */
    // Adding an item
    connect(ui->btnAddItem, &QPushButton::clicked, this,&MainWindow::handleAddItem);
    //*************
}

// My Additions
// Code to Populate List inside graphics tab

void MainWindow::populateItemList() {
    // Define the paths and corresponding QListWidget names
    QList<QPair<QString, QString>> folderPaths = {
        {"backgroundList", "C:/Users/Admin/source/repos/Timber/graphics/background"},
        {"playerList", "C:/Users/Admin/source/repos/Timber/graphics/player"},
        {"cloudList", "C:/Users/Admin/source/repos/Timber/graphics/cloud"},
        {"beeList", "C:/Users/Admin/source/repos/Timber/graphics/bee"},
        {"treeList", "C:/Users/Admin/source/repos/Timber/graphics/tree"},
        {"branchList", "C:/Users/Admin/source/repos/Timber/graphics/branch"},
        {"logList", "C:/Users/Admin/source/repos/Timber/graphics/log"},
        {"ripList", "C:/Users/Admin/source/repos/Timber/graphics/rip"},
        {"chopList", "C:/Users/Admin/source/repos/Timber/Sound/chop"},
        {"deathList", "C:/Users/Admin/source/repos/Timber/Sound/death"},
        {"ootList", "C:/Users/Admin/source/repos/Timber/Sound/oot"},
        {"hudList", "C:/Users/Admin/source/repos/Timber/Fonts/hud"},
        {"messageList", "C:/Users/Admin/source/repos/Timber/Fonts/message"},
        {"scoreList", "C:/Users/Admin/source/repos/Timber/Fonts/score"}
    };

    // Filters for different file types
    QMap<QString, QStringList> filters;
    filters["graphics"] = QStringList() << "*.png" << "*.jpg" << "*.jpeg" << "*.bmp";
    filters["audio"] = QStringList() << "*.mp3" << "*.wav";
    filters["fonts"] = QStringList() << "*.ttf";

    // Iterate over each folder path and populate the corresponding QListWidget
    for (auto& folder : folderPaths) {
        QListWidget* listWidget = findChild<QListWidget*>(folder.first);
        if (listWidget) {
            listWidget->clear(); // Clear existing items, if any

            QString folderType = folder.second.contains("graphics") ? "graphics" :
                                     folder.second.contains("Sound") ? "audio" : "fonts";

            QDirIterator it(folder.second, filters[folderType], QDir::Files | QDir::NoDotAndDotDot);
            while (it.hasNext()) {
                it.next();
                listWidget->addItem(it.fileName()); // Add file names to the list
            }
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
        populateItemList();
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
