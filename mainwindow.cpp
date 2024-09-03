#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtMultimedia/QMediaPlayer>

/*
 * Constructor
*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Function Call :  Populating image list from corresponding graphics folder
    populateItemList();

    //Function Call :  Connecting UI Components for Image Preview
    initializeUIComponents();

    //Function Call: connection signals for all relevant QListWidget objects
    setUpListWidgetConnections();

    //Function Call: Adding an item to the existing assets
    setUPAddItemButton();

    //Function Call: Load Assets from assetConfig.json
    loadCurrentAssetsFromConfig();

    //Function Call: highlight current assets in timber
    highlightCurrentAssets();
}
/*
 * Initializing UI Components for Image Preview Functionality
*/
void MainWindow::initializeUIComponents(){

    // Connection for Image Preview
    scene = new QGraphicsScene(this);
    ui->imagePreview->setScene(scene);
    ui->imagePreview->setAlignment(Qt::AlignCenter);

}
/*
 * Connecting UI Components with respective file paths for Asset List View
*/
void MainWindow::setUpListWidgetConnections(){
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
     * Audio
    */
    // Initializing media player

    //mediaPlayer = new QMediaPlayer(this);

    //Initializing Play Button
    // playButton = new QPushButton(this);
    // playButton->setIcon(QIcon(":/Resources/playbutton.png"));
    // playButton->setIconSize(QSize(64,64));
    // playButton->setStyleSheet("background-color: transparent; border: none;");
    // playButton->hide();
    // playButton->setCursor(Qt::PointingHandCursor);

    // Connect the play button to the slot that handles playing audio
    //connect(playButton,&QPushButton::clicked,this,&MainWindow::handlePlayButtonClicked);

    /*
     * Iteration for Images and Audio
    */
}
/*
 * Populating Assets in the Asset List View
*/
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

/*
 * Displaying Preview Image in the Image Preview UI space
*/
void MainWindow::updateImagePreview(const QString &imagePath){
    QString fileExtension = QFileInfo(imagePath).suffix().toLower();
    scene->clear(); // Clear Previous items

    //playButton->hide(); // Hide the play button by default

    if(fileExtension == "png" || fileExtension == "jpg" || fileExtension == "jpeg" || fileExtension == "bmp"){
        // Handle Image Files
        QPixmap image(imagePath);
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
    }/*else if(fileExtension == "mp3" || fileExtension == "wav"){
        // Handle Audio Files
        mediaPlayer->setSource(QUrl::fromLocalFile(imagePath));

        // Show and position the play button
        playButton->move(ui->imagePreview->width() / 2 - playButton->width() / 2, ui->imagePreview->height() / 2 - playButton->height() / 2);
        playButton->show();
    }*/

    // Check if image is not null or not

}

/*
 * Handling Adding asset
*/
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
            targetDirectory = "C:/Users/Admin/source/repos/Timber/graphics/background";
            break;
        case 1: // Player
            targetDirectory = "C:/Users/Admin/source/repos/Timber/graphics/player";
            break;
        case 2: // Cloud
            targetDirectory = "C:/Users/Admin/source/repos/Timber/graphics/cloud";
            break;
        case 3: // Bee
            targetDirectory = "C:/Users/Admin/source/repos/Timber/graphics/bee";
            break;
        case 4: // Tree
            targetDirectory = "C:/Users/Admin/source/repos/Timber/graphics/tree";
            break;
        case 5: // Branch
            targetDirectory = "C:/Users/Admin/source/repos/Timber/graphics/branch";
            break;
        case 6: //Log
            targetDirectory = "C:/Users/Admin/source/repos/Timber/graphics/log";
            break;
        case 7: // Grave Stone
            targetDirectory = "C:/Users/Admin/source/repos/Timber/graphics/rip";
            break;
        default:
            targetDirectory = "C:/Users/Admin/source/repos/Timber/graphics";
            break;
        }
    }

    // Audio Tab
    else if (currentTabIndex == ui->MaintabWidget->indexOf(ui->audioTab)){
        int subTabIndex = ui->audioSubTabs->currentIndex();
        switch(subTabIndex){
        case 0: //chop
            targetDirectory = "C:/Users/Admin/source/repos/Timber/Sound/chop";
            break;
        case 1: // death
            targetDirectory = "C:/Users/Admin/source/repos/Timber/Sound/death";
            break;
        case 2: // out of time
            targetDirectory = "C:/Users/Admin/source/repos/Timber/Sound/oot";
            break;
        default:
            targetDirectory = "C:/Users/Admin/source/repos/Timber/Sound";
            break;
        }
    }

    // Fonts Tab
    else if (currentTabIndex == ui->MaintabWidget->indexOf(ui->fontTab)){
        int subTabIndex = ui->fontSubTabs->currentIndex();
        switch(subTabIndex){
        case 0: //heads up display
            targetDirectory = "C:/Users/Admin/source/repos/Timber/Fonts/hud";
            break;
        case 1: // message
            targetDirectory = "C:/Users/Admin/source/repos/Timber/Fonts/score";
            break;
        case 2: // score
            targetDirectory = "C:/Users/Admin/source/repos/Timber/Fonts/message";
            break;
        default:
            targetDirectory = "C:/Users/Admin/source/repos/Timber/Fonts";
            break;
        }
    }

    // Constructing the target file path
    QFileInfo fileInfo(filePath);
    QString targetFilePath = targetDirectory + "/" + fileInfo.fileName();

    // Copy the file to the target directory
    if(QFile::copy(filePath,targetFilePath)){
        ui->addItemStatus->setProperty("status","success");
        ui->addItemStatus->setText("File Added");
        ui->addItemStatus->style()->unpolish(ui->addItemStatus);
        ui->addItemStatus->style()->polish(ui->addItemStatus);
        populateItemList();
    }else{
        ui->addItemStatus->setProperty("status","error");
        ui->addItemStatus->setText("Failed");
        ui->addItemStatus->style()->unpolish(ui->addItemStatus);
        ui->addItemStatus->style()->polish(ui->addItemStatus);
        QMessageBox::warning(this, "Error", "Failed to add file to the directory.");
    }
}

/*
 * Push Button : Add Item
*/
void MainWindow::setUPAddItemButton(){
    connect(ui->btnAddItem, &QPushButton::clicked, this,&MainWindow::handleAddItem);
}
/*
 * Push Button : Play Audio
*/
// void MainWindow::handlePlayButtonClicked(){
//     if (mediaPlayer->playbackState() == QMediaPlayer::PlayingState) {
//         mediaPlayer->stop();
//     } else {
//         mediaPlayer->play();
//     }
// }
/*
 * Parse data from assetConfig.json
*/

QSet<QString> MainWindow::loadCurrentAssetsFromConfig(){
    QFile configFile("C:/Users/Admin/source/repos/Timber/Timber/assetConfig.json");
    if(!configFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Failed to open config file.";
        return QSet<QString>();
    }
    QByteArray data = configFile.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject jsonObj = doc.object();

    QSet<QString> currentAssets;

    QJsonObject graphicsObj = jsonObj["graphics"].toObject();
    for (const QString &key : graphicsObj.keys()) {
        currentAssets.insert(graphicsObj[key].toString());
    }
    //add other assets later

    return currentAssets;
}

/*
 * Testing: loadCurrentAssetsFromConfig
*/
void MainWindow::testloadCurrentAssetsFromConfig(){
    QSet<QString> assets = loadCurrentAssetsFromConfig();

    qDebug()<<"Loaded Assets:";
    for(const QString &asset:assets){
        qDebug()<<asset;
    }
}
/*
 * Highlighting current assets in Timber using assetConfig.json file
*/
void MainWindow::highlightCurrentAssets(){
    // Load and extract data from the config file
    QSet<QString> currentAssets = loadCurrentAssetsFromConfig();

    // Create a new set containing only the filenames
    QSet<QString> currentAssetNames;
    for (const QString &fullPath : currentAssets) {
        QFileInfo fileInfo(fullPath);
        QString fileName = fileInfo.fileName();
        currentAssetNames.insert(fileName);
        //qDebug() << "Extracted filename:" << fileName;
    }

    // ListWidgets to Check
    QList<QListWidget*> listWidgets = {ui->backgroundList, ui->playerList, ui->cloudList,
                                        ui->beeList, ui->treeList, ui->branchList,
                                        ui->logList, ui->ripList, ui->chopList,
                                        ui->deathList, ui->ootList, ui->hudList,
                                        ui->messageList, ui->scoreList};

    for(QListWidget* listWidget : listWidgets){
        for(int i=0;i<listWidget->count();++i){
            QListWidgetItem* item = listWidget->item(i);
            QString assetName = item->text();

            //qDebug() << "Checking asset:" << assetName;

            if(currentAssetNames.contains(assetName)){
                // Highlight the current item
                item->setBackground(Qt::gray);
            }
        }
    }

}
/*
 * Destructor
*/
MainWindow::~MainWindow()
{
    delete ui;
}
