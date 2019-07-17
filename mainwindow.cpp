#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "denglu.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setCursor(QCursor(Qt::PointingHandCursor));
    ui->denglu->setCursor(QCursor(Qt::PointingHandCursor));

}

MainWindow::~MainWindow()
{    
    delete ui;
}


void MainWindow::on_denglu_clicked()
{
    ad_denglu = new admin_denglu(this);
    ad_denglu->show();
}

void MainWindow::on_pushButton_clicked()
{
    vis = new  visitor(this);
    vis->show();
}
