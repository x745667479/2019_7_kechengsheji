#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include "datastructor.h"
#include <QListWidget>
#include <QListWidgetItem>
#include "sort.h"
#include "view_info.h"
namespace Ui {
class View;
}

class View : public QMainWindow
{
    Q_OBJECT
signals:
    void sendData(int);
private slots:
    void getData(float,float,float,int);

    void on_sort_len_clicked();

    void on_go_clicked();

    void on_view_itemClicked(QListWidgetItem *item);

    void on_sort_com_clicked();

    void on_look_info_clicked();

public:
    explicit View(QWidget *parent = nullptr);
    ~View();

private:
    Ui::View *ui;
    VertexType *head;
    VertexType *r;
    float x;
    float y;
    float time;
    int pos;
    int *jilu;
    int lengenth;
    int target;
    view_info* info;
};

#endif // VIEW_H
