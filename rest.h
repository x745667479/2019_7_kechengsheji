#ifndef REST_H
#define REST_H

#include <QMainWindow>
#include "datastructor.h"
#include <QListWidget>
#include <QListWidgetItem>
#include "merg_sort.h"
#include "sort.h"

namespace Ui {
class Rest;
}

class Rest : public QMainWindow
{
    Q_OBJECT
private slots:
    void getData(float,float,float,int);
    void on_sort_len_clicked();

    void on_go_clicked();

    void on_rest_itemClicked(QListWidgetItem *item);

public:
    explicit Rest(QWidget *parent = nullptr);
    ~Rest();

private:
    Ui::Rest *ui;
    VertexType *head;
    VertexType *r;
    float x;
    float y;
    float time;
    int pos;
    int *jilu;
    int lengenth;
    int target;
};

#endif // REST_H
