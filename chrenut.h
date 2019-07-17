#ifndef CHRENUT_H
#define CHRENUT_H

#include <QMainWindow>
#include <iostream>
#include <QMessageBox>
#include <QDebug>
#include <QListWidget>
#include <QListWidgetItem>
#include "ch_in_renut.h"
namespace Ui {
class chRenut;
}

class chRenut : public QMainWindow
{
    Q_OBJECT
signals:
    void sendData(int);

public:
    explicit chRenut(QWidget *parent = nullptr);
    ~chRenut();

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

private:
    Ui::chRenut *ui;
    ch_in_renut *ch_renut;
    int target;

};

#endif // CHRENUT_H
