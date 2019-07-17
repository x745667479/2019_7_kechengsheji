#ifndef CH_IN_REST_H
#define CH_IN_REST_H

#include <QMainWindow>
#include "datastructor.h"
namespace Ui {
class ch_in_rest;
}

class ch_in_rest : public QMainWindow
{
    Q_OBJECT
private slots:
     void getData(int,VertexType*);
     void on_pushButton_clicked();

public:
    explicit ch_in_rest(QWidget *parent = nullptr);
    ~ch_in_rest();

private:
    Ui::ch_in_rest *ui;
    int get_target;
    VertexType* v;
    VertexType* head;
};

#endif // CH_IN_REST_H
