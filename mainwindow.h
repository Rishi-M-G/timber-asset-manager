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

    void updateImagePreview(const QString& imagePath);
    void populateItemList();
    void handleAddItem();
    void handlePlayButtonClicked();
    void initializeUIComponents();
    void setUpListWidgetConnections();
    void setUPAddItemButton();

    //************
};
#endif // MAINWINDOW_H
