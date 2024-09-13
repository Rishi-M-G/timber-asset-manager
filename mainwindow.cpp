#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtMultimedia/QMediaPlayer>

/*
 * Constructor
*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , assetsLoaded(false)
{
    ui->setupUi(this);

    populateItemList();//Function Call :  Populating image list from corresponding graphics folder
    initializeUIComponents();//Function Call :  Connecting UI Components for Image Preview
    setUpListWidgetConnections();//Function Call: connection signals for all relevant QListWidget objects
    setUPAddItemButton();//Function Call: Adding an item to the existing assets
    loadCurrentAssetsFromConfig();//Function Call: Load Assets from assetConfig.json
    //testloadCurrentAssetsFromConfig();
    highlightCurrentAssets();//Function Call: highlight current assets in timber
    setUPRemoveItemButton();//Function Call: Removing an item to the existing assets
    setUPRemoveItemButtonStatus();//Function Call: Switching remove button status
    //Function Call: remove button status
    //updateRemoveButtonState();
    setUPSetAsCurrentButton();//Function Call: Set As Current button status
    setUPRunGameItemButton();//Function Call: Run Game Button
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
        case 1: // score
            targetDirectory = "C:/Users/Admin/source/repos/Timber/Fonts/score";
            break;
        case 2: // message
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
 * Push Button : Remove Item
*/
void MainWindow::setUPRemoveItemButton(){
    connect(ui->btnRemoveItem,&QPushButton::clicked,this,&MainWindow::handleRemoveItem);
}
/*
 * Remove Item Button status
*/
void MainWindow::setUPRemoveItemButtonStatus(){
    connect(ui->backgroundList, &QListWidget::itemSelectionChanged, this, &MainWindow::updateRemoveButtonState);
    connect(ui->playerList, &QListWidget::itemSelectionChanged, this, &MainWindow::updateRemoveButtonState);
    connect(ui->cloudList, &QListWidget::itemSelectionChanged, this, &MainWindow::updateRemoveButtonState);
    connect(ui->beeList, &QListWidget::itemSelectionChanged, this, &MainWindow::updateRemoveButtonState);
    connect(ui->treeList, &QListWidget::itemSelectionChanged, this, &MainWindow::updateRemoveButtonState);
    connect(ui->branchList, &QListWidget::itemSelectionChanged, this, &MainWindow::updateRemoveButtonState);
    connect(ui->logList, &QListWidget::itemSelectionChanged, this, &MainWindow::updateRemoveButtonState);
    connect(ui->ripList, &QListWidget::itemSelectionChanged, this, &MainWindow::updateRemoveButtonState);
    connect(ui->chopList, &QListWidget::itemSelectionChanged, this, &MainWindow::updateRemoveButtonState);
    connect(ui->deathList, &QListWidget::itemSelectionChanged, this, &MainWindow::updateRemoveButtonState);
    connect(ui->ootList, &QListWidget::itemSelectionChanged, this, &MainWindow::updateRemoveButtonState);
    connect(ui->hudList, &QListWidget::itemSelectionChanged, this, &MainWindow::updateRemoveButtonState);
    connect(ui->messageList, &QListWidget::itemSelectionChanged, this, &MainWindow::updateRemoveButtonState);
    connect(ui->scoreList, &QListWidget::itemSelectionChanged, this, &MainWindow::updateRemoveButtonState);
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
    // Return Cached assets if already loaded
    if(assetsLoaded){
        return cachedAssets;
    }

    QFile configFile("C:/Users/Admin/source/repos/Timber/Debug/assetConfigCopy.json");
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

    QJsonObject audioObj = jsonObj["audio"].toObject();
    for(const QString &key : audioObj.keys()){
        currentAssets.insert(audioObj[key].toString());
    }

    QJsonObject fontsObj = jsonObj["fonts"].toObject();
    for(const QString &key : fontsObj.keys()){
        currentAssets.insert(fontsObj[key].toString());
    }



    // Cache the assets
    cachedAssets = currentAssets;
    assetsLoaded = true;
    return cachedAssets;
}

/*
 * Reload Assets
*/
void MainWindow::reloadAssets(){
    assetsLoaded = false;
    cachedAssets = loadCurrentAssetsFromConfig();
}


/*
 * Testing: loadCurrentAssetsFromConfig
*/
void MainWindow::testloadCurrentAssetsFromConfig(){
    QSet<QString> assets = cachedAssets;

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
    QSet<QString> currentAssets = cachedAssets;

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
 * Removing an asset from Asset List and from the respective Target Folder
*/
void MainWindow::handleRemoveItem(){
    QListWidget* activeListWidget = nullptr;
    QString targetDirectory;

    // Determine the currenlty active tab and subtab
    int currentTabIndex = ui->MaintabWidget->currentIndex();

    if(currentTabIndex == ui->MaintabWidget->indexOf(ui->graphicsTab)){
        int subTabIndex = ui->graphicSubTabs->currentIndex();
        switch(subTabIndex){
        case 0: // Background
            activeListWidget = ui->backgroundList;
            targetDirectory = "C:/Users/Admin/source/repos/Timber/graphics/background";
            break;
        case 1: // Player
            activeListWidget = ui->playerList;
            targetDirectory = "C:/Users/Admin/source/repos/Timber/graphics/player";
            break;
        case 2: // Cloud
            activeListWidget = ui->cloudList;
            targetDirectory = "C:/Users/Admin/source/repos/Timber/graphics/cloud";
            break;
        case 3: // Bee
            activeListWidget = ui->beeList;
            targetDirectory = "C:/Users/Admin/source/repos/Timber/graphics/bee";
            break;
        case 4: // Tree
            activeListWidget = ui->treeList;
            targetDirectory = "C:/Users/Admin/source/repos/Timber/graphics/tree";
            break;
        case 5: // Branch
            activeListWidget = ui->branchList;
            targetDirectory = "C:/Users/Admin/source/repos/Timber/graphics/branch";
            break;
        case 6: //Log
            activeListWidget = ui->logList;
            targetDirectory = "C:/Users/Admin/source/repos/Timber/graphics/log";
            break;
        case 7: // Grave Stone
            activeListWidget = ui->ripList;
            targetDirectory = "C:/Users/Admin/source/repos/Timber/graphics/rip";
            break;
        default:
            return;
        }
    }else if(currentTabIndex == ui->MaintabWidget->indexOf(ui->audioTab)){
        int subTabIndex = ui->audioSubTabs->currentIndex();
        switch(subTabIndex){
        case 0: //chop
            activeListWidget = ui->chopList;
            targetDirectory = "C:/Users/Admin/source/repos/Timber/Sound/chop";
            break;
        case 1: // death
            activeListWidget = ui->deathList;
            targetDirectory = "C:/Users/Admin/source/repos/Timber/Sound/death";
            break;
        case 2: // out of time
            activeListWidget = ui->ootList;
            targetDirectory = "C:/Users/Admin/source/repos/Timber/Sound/oot";
            break;
        default:
            return;
        }
    }else if(currentTabIndex == ui->MaintabWidget->indexOf(ui->fontTab)){
        int subTabIndex = ui->fontSubTabs->currentIndex();
        switch(subTabIndex){
        case 0: //heads up display
            activeListWidget = ui->hudList;
            targetDirectory = "C:/Users/Admin/source/repos/Timber/Fonts/hud";
            break;
        case 1: // score
            activeListWidget = ui->messageList;
            targetDirectory = "C:/Users/Admin/source/repos/Timber/Fonts/score";
            break;
        case 2: // message
            activeListWidget = ui->scoreList;
            targetDirectory = "C:/Users/Admin/source/repos/Timber/Fonts/message";
            break;
        default:
            return;
        }
    }

    if(!activeListWidget)
        return;

    // Get selected item
    QListWidgetItem* selectedItem = activeListWidget->currentItem();
    if(!selectedItem)
        return;

    QString assetName = selectedItem->text();
    QString fullPath = targetDirectory+"/"+assetName;

    // Check if this asset is currently in use
    QSet<QString> currentAssets = cachedAssets;

    // Create a new set containing only the filenames
    QSet<QString> currentAssetNames;
    for (const QString &fullPath : currentAssets) {
        QFileInfo fileInfo(fullPath);
        QString fileName = fileInfo.fileName();
        currentAssetNames.insert(fileName);
    }
    if(currentAssetNames.contains(assetName)){
        QMessageBox::warning(this,"Cannot Remove","This asset is currently in use, and cannot be removed.");
        return;
    }

    // If asset is not currently in use, Remove File from the Directory
    if(QFile::remove(fullPath)){
        delete selectedItem;
        qDebug()<<"Removed Asset:" <<fullPath;
    }else{
        QMessageBox::warning(this,"Error","Failed to remove this asset.");
    }
}

/*
 * Switching Remove Item Button's Status
*/
void MainWindow::updateRemoveButtonState(){
    bool hasSelection = false;

    // Check all list widgets for a selected item
    QList<QListWidget*> listWidgets = {ui->backgroundList, ui->playerList, ui->cloudList,
                                        ui->beeList, ui->treeList, ui->branchList,
                                        ui->logList, ui->ripList, ui->chopList,
                                        ui->deathList, ui->ootList, ui->hudList,
                                        ui->messageList, ui->scoreList};

    for(QListWidget* listWidget : listWidgets){
        if(listWidget->selectedItems().count() > 0){
            hasSelection = true;
            break;
        }
    }
    ui->btnRemoveItem->setEnabled(hasSelection);
    ui->btnRemoveItem->setVisible(hasSelection);
}

/*
 * Switching Set As Current Item Button's Status
*/
void MainWindow::updateSetCurrentButtonState(){
    bool showSetAsCurrentButton = false;

    QListWidget* activeListWidget = nullptr;

    // Determining the currently active tab and subtab
    int currentTabIndex = ui->MaintabWidget->currentIndex();

    if(currentTabIndex == ui->MaintabWidget->indexOf(ui->graphicsTab)){
        int subTabIndex = ui->graphicSubTabs->currentIndex();
        switch(subTabIndex){
        case 0: // Background
            activeListWidget = ui->backgroundList;
            break;
        case 1: // Player
            activeListWidget = ui->playerList;
            break;
        case 2: // Cloud
            activeListWidget = ui->cloudList;
            break;
        case 3: // Bee
            activeListWidget = ui->beeList;
            break;
        case 4: // Tree
            activeListWidget = ui->treeList;
            break;
        case 5: // Branch
            activeListWidget = ui->branchList;
            break;
        case 6: //Log
            activeListWidget = ui->logList;
            break;
        case 7: // Grave Stone
            activeListWidget = ui->ripList;
            break;
        default:
            return;
        }
    }else if(currentTabIndex == ui->MaintabWidget->indexOf(ui->audioTab)){
        int subTabIndex = ui->audioSubTabs->currentIndex();
        switch(subTabIndex){
        case 0: //chop
            activeListWidget = ui->chopList;
            break;
        case 1: // death
            activeListWidget = ui->deathList;
            break;
        case 2: // out of time
            activeListWidget = ui->ootList;
            break;
        default:
            return;
        }
    }else if(currentTabIndex == ui->MaintabWidget->indexOf(ui->fontTab)){
        int subTabIndex = ui->fontSubTabs->currentIndex();
        switch(subTabIndex){
        case 0: //heads up display
            activeListWidget = ui->hudList;
            break;
        case 1: // score
            activeListWidget = ui->messageList;
            break;
        case 2: // message
            activeListWidget = ui->scoreList;
            break;
        default:
            return;
        }
    }

    if(!activeListWidget){
        ui->btnSetAsCurrent->setVisible(false);
        return;
    }

    // Get Selected item
    QListWidgetItem* selectedItem = activeListWidget->currentItem();
    if(!selectedItem){
        ui->btnSetAsCurrent->setVisible(false);
        return;
    }

    QString selectedAsset = selectedItem->text();

    // Check if this is already the current asset in the config
    QSet<QString> currentAssets = cachedAssets;

    // Create a new set containing only the filenames of current assets
    QSet<QString> currentAssetNames;
    for (const QString &fullPath : currentAssets) {
        QFileInfo fileInfo(fullPath);
        QString fileName = fileInfo.fileName();
        currentAssetNames.insert(fileName);
    }

    if(!currentAssetNames.contains(selectedAsset)){
        showSetAsCurrentButton = true;
    }
    ui->btnSetAsCurrent->setVisible(showSetAsCurrentButton);
}

/*
 * Update Config File: Setting the Selected Asset
*/
void MainWindow::setCurrentAsset(){
    QListWidget* activeListWidget = nullptr;
    QString targetDirectory;
    QString assetType;
    QString assetCategory;

    // Determining the currently active tab and subtab
    int currentTabIndex = ui->MaintabWidget->currentIndex();

    if(currentTabIndex == ui->MaintabWidget->indexOf(ui->graphicsTab)){
        // Graphics Tab
        assetCategory = "graphics";
        int subTabIndex = ui->graphicSubTabs->currentIndex();
        switch(subTabIndex){
        case 0: // Background
            activeListWidget = ui->backgroundList;
            targetDirectory = "C:/Users/Admin/source/repos/Timber/graphics/background";
            assetType="background";
            break;
        case 1: // Player
            activeListWidget = ui->playerList;
            targetDirectory = "C:/Users/Admin/source/repos/Timber/graphics/player";
            assetType="player";
            break;
        case 2: // Cloud
            activeListWidget = ui->cloudList;
            targetDirectory = "C:/Users/Admin/source/repos/Timber/graphics/cloud";
            assetType="cloud";
            break;
        case 3: // Bee
            activeListWidget = ui->beeList;
            targetDirectory = "C:/Users/Admin/source/repos/Timber/graphics/bee";
            assetType="bee";
            break;
        case 4: // Tree
            activeListWidget = ui->treeList;
            targetDirectory = "C:/Users/Admin/source/repos/Timber/graphics/tree";
            assetType="tree";
            break;
        case 5: // Branch
            activeListWidget = ui->branchList;
            targetDirectory = "C:/Users/Admin/source/repos/Timber/graphics/branch";
            assetType="branch";
            break;
        case 6: //Log
            activeListWidget = ui->logList;
            targetDirectory = "C:/Users/Admin/source/repos/Timber/graphics/log";
            assetType="log";
            break;
        case 7: // Grave Stone
            activeListWidget = ui->ripList;
            targetDirectory = "C:/Users/Admin/source/repos/Timber/graphics/rip";
            assetType="rip";
            break;
        default:
            return;
        }
    }else if(currentTabIndex == ui->MaintabWidget->indexOf(ui->audioTab)){
        // Audio Tab
        assetCategory = "audio";
        int subTabIndex = ui->audioSubTabs->currentIndex();
        switch(subTabIndex){
        case 0: //chop
            activeListWidget = ui->chopList;
            targetDirectory = "C:/Users/Admin/source/repos/Timber/Sound/chop";
            assetType="chop";
            break;
        case 1: // death
            activeListWidget = ui->deathList;
            targetDirectory = "C:/Users/Admin/source/repos/Timber/Sound/death";
            assetType="death";
            break;
        case 2: // out of time
            activeListWidget = ui->ootList;
            targetDirectory = "C:/Users/Admin/source/repos/Timber/Sound/oot";
            assetType="oot";
            break;
        default:
            return;
        }
    }else if(currentTabIndex == ui->MaintabWidget->indexOf(ui->fontTab)){
        // Fonts
        assetCategory = "fonts";
        int subTabIndex = ui->fontSubTabs->currentIndex();
        switch(subTabIndex){
        case 0: //heads up display
            activeListWidget = ui->hudList;
            targetDirectory = "C:/Users/Admin/source/repos/Timber/Fonts/hud";
            assetType="hud";
            break;
        case 1: // score
            activeListWidget = ui->messageList;
            targetDirectory = "C:/Users/Admin/source/repos/Timber/Fonts/score";
            assetType="score";
            break;
        case 2: // message
            activeListWidget = ui->scoreList;
            targetDirectory = "C:/Users/Admin/source/repos/Timber/Fonts/message";
            assetType="message";
            break;
        default:
            return;
        }
    }

    if(!activeListWidget)
        return;

    // Get Selected Item
    QListWidgetItem* selectedItem = activeListWidget->currentItem();

    if(!selectedItem)
        return;

    QString selectedAsset = selectedItem->text();
    QString fullPath = targetDirectory + "/" + selectedAsset;

    // Open the config file for writing
    QFile configFile("C:/Users/Admin/source/repos/Timber/Debug/assetConfigCopy.json");
    if(!configFile.open(QIODevice::ReadWrite | QIODevice::Text)){
        qWarning()<<"Failed to open config file for reading and writing.";
        return;
    }

    // Read the current config into a JSON document
    QByteArray data = configFile.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject jsonObj = doc.object();

    //Update the relevant asset category and asset type
    QJsonObject categoryObj = jsonObj[assetCategory].toObject();
    categoryObj[assetType] = fullPath;
    jsonObj[assetCategory] = categoryObj;

    // Write back the updated JSON to the file
    doc.setObject(jsonObj);
    configFile.resize(0); // Clear the file content
    configFile.write(doc.toJson());
    configFile.close();

    // Provide Message to the user
    QMessageBox::information(this, "Success","Asset has been set as the current" + assetType + "asset in" + assetCategory + ".");
}

/*
 * Push Button : Add Item
*/
void MainWindow::setUPSetAsCurrentButton() {
    connect(ui->btnSetAsCurrent, &QPushButton::clicked, this, &MainWindow::setCurrentAsset);
}

/*
 * Run Game
*/
void MainWindow::onRunGameButtonClicked(){
    // path of the debug executable
    QString executablePath = "C:/Users/Admin/source/repos/Timber/Debug/Timber.exe";

    // Creating a process to run executable
    QProcess *process = new QProcess(this);

    //Set working directory
    process->setWorkingDirectory("C:/Users/Admin/source/repos/Timber/Debug");
    // Start the executable
    process->start(executablePath);

    // Check if the process starts correctly
    if (!process->waitForStarted()) {
        // If it failed to start, show an error message
        QMessageBox::warning(this, "Error", "Failed to start the game.");
        qDebug() << "Error: " << process->errorString();
    } else {
        qDebug() << "Game started successfully.";
    }
}

/*
 * Push Button : Run Game
*/
void MainWindow::setUPRunGameItemButton(){
    connect(ui->btnRunGame, &QPushButton::clicked, this, &MainWindow::onRunGameButtonClicked);
}

/*
 * Destructor
*/
MainWindow::~MainWindow()
{
    delete ui;
}
