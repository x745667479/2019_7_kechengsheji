#ifndef INRENUT_H
#define INRENUT_H

#include <QMainWindow>
#include "datastructor.h"
#include <QMessageBox>
#include "len_point.h"
namespace Ui {
class inRenut;
}

class inRenut : public QMainWindow
{
    Q_OBJECT

public:
    explicit inRenut(QWidget *parent = nullptr);
    ~inRenut();

private slots:
    void on_submit_one_clicked();

    void on_submmit_renut_dish_clicked();

    void on_renut_submmit_clicked();

private:
    Ui::inRenut *ui;
    VertexType *renut;
    bool choice;
    int i;
};

#endif // INRENUT_H
