#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
// My Additions
#include <QDir>
#include <QFileInfoList>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QMessageBox>
#include <QDirIterator>
#include <QListWidget>
#include <QPushButton>
#include <QSet>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QProcess>


//**********

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    // My Additions
    QGraphicsScene* scene;
    // QMediaPlayer* mediaPlayer;
    // QPushButton* playButton;

    QSet<QString> cachedAssets;
    bool assetsLoaded;


    void updateImagePreview(const QString& imagePath);
    void populateItemList();
    void handleAddItem();
    void handlePlayButtonClicked();
    void initializeUIComponents();
    void setUpListWidgetConnections();
    void setUPAddItemButton();
    QSet<QString> loadCurrentAssetsFromConfig();
    void highlightCurrentAssets();
    void testloadCurrentAssetsFromConfig();
    void handleRemoveItem();
    void updateRemoveButtonState();
    void setUPRemoveItemButton();
    void setUPRemoveItemButtonStatus();
    void updateSetCurrentButtonState();
    void setCurrentAsset();
    void setUPSetAsCurrentButton();
    void onRunGameButtonClicked();
    void setUPRunGameItemButton();
    void reloadAssets();

    //************
};
#endif // MAINWINDOW_H
