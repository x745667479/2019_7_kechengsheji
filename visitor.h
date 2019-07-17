#ifndef VISITOR_H
#define VISITOR_H

#include <QMainWindow>
#include "Renut.h"
#include "Rest.h"
#include "View.h"
#include "recommend.h"

namespace Ui {
class visitor;
}

class visitor : public QMainWindow
{
    Q_OBJECT
signals:
    void sendData(float,float,float,int);
public:
    explicit visitor(QWidget *parent = nullptr);
    ~visitor();

private slots:
    void on_rest_clicked();

    void on_view_clicked();

    void on_renut_clicked();


    void on_sub_pos_clicked();

    void on_sub_time_clicked();

private:
    Ui::visitor *ui;
    Renut *ren;
    Rest *res;
    View *vie;
    float x;
    float y;
    float time;
    bool pos_ready;
    bool time_ready;
    int pos;

};

#endif // VISITOR_H
