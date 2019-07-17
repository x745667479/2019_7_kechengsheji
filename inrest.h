#ifndef INREST_H
#define INREST_H

#include <QMainWindow>
#include <QFile>
#include "datastructor.h"
#include <QMessageBox>
#include "len_point.h"
namespace Ui {
class inRest;
}

class inRest : public QMainWindow
{
    Q_OBJECT

public:
    explicit inRest(QWidget *parent = nullptr);
    ~inRest();

private slots:
    void on_submit_rest_clicked();

private:
    Ui::inRest *ui;
    VertexType *rest;


};

#endif // INREST_H
