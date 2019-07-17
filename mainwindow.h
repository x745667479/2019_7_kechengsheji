#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include "admin_denglu.h"
#include "visitor.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_denglu_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    admin_denglu *ad_denglu;
    visitor *vis;
};

#endif // MAINWINDOW_H
