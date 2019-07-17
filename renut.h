#ifndef RENUT_H
#define RENUT_H

#include <QMainWindow>
#include "datastructor.h"
#include <QListWidget>
#include <QListWidgetItem>
#include "sort.h"
#include "renut_info.h"
namespace Ui {
class Renut;
}

class Renut : public QMainWindow
{
    Q_OBJECT
signals:
    void sendData(int);
private slots:
    void getData(float,float,float,int);

    void on_sort_len_clicked();

    void on_renut_itemClicked(QListWidgetItem *item);

    void on_go_clicked();

    void on_sort_comm_clicked();

    void on_look_info_clicked();

public:
    explicit Renut(QWidget *parent = nullptr);
    ~Renut();

private:
    Ui::Renut *ui;
    VertexType *head;
    VertexType *r;
    float x;
    float y;
    float time;
    int pos;
    int *jilu;
    int lengenth;
    int target;
    renut_info* info;
};

#endif // RENUT_H
