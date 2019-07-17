#ifndef CHREST_H
#define CHREST_H

#include <QMainWindow>
#include <iostream>
#include "datastructor.h"
#include <QMessageBox>
#include <QDebug>
#include "ch_in_rest.h"
#include <QListWidget>
#include <QListWidgetItem>
using namespace std;

namespace Ui {
class chRest;
}

class chRest : public QMainWindow
{
    Q_OBJECT

signals:
    void sendData(int,VertexType*);

public:
    explicit chRest(QWidget *parent = nullptr);
    ~chRest();

private slots:
    void on_pushButton_clicked();

    void on_rest_itemClicked(QListWidgetItem *item);

private:
    Ui::chRest *ui;
    ch_in_rest *ch_rest;
    VertexType *head;
    VertexType *r;
    int target;

};

#endif // CHREST_H
