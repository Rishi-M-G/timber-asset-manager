#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
// My Additions
#include <QDir>
#include <QFileInfoList>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QMessageBox>
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
    void updateImagePreview(const QString& imagePath);
    void populateImageList();
    void handleAddItem();

    //************
};
#endif // MAINWINDOW_H
