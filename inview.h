#ifndef INVIEW_H
#define INVIEW_H

#include <QMainWindow>
#include "datastructor.h"
#include <fstream>
#include <QMessageBox>
#include "len_point.h"
namespace Ui {
class inView;
}

class inView : public QMainWindow
{
    Q_OBJECT

public:
    explicit inView(QWidget *parent = nullptr);
    ~inView();

private slots:

    void on_submit_one_act_clicked();
    void on_submit_the_act_clicked();
    void on_submint_view_clicked();

private:
    Ui::inView *ui;
    bool choice;
    VertexType *act;
    int i;

};

#endif // INVIEW_H
