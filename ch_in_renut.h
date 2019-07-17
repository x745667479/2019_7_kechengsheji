#ifndef CH_IN_RENUT_H
#define CH_IN_RENUT_H

#include <QMainWindow>
#include "datastructor.h"
namespace Ui {
class ch_in_renut;
}

class ch_in_renut : public QMainWindow
{
    Q_OBJECT
private slots:
     void getData(int);
     void on_pushButton_clicked();

public:
    explicit ch_in_renut(QWidget *parent = nullptr);
    ~ch_in_renut();

private:
    Ui::ch_in_renut *ui;
    int get_target;
    VertexType *head;
    VertexType* v;

};

#endif // CH_IN_RENUT_H
