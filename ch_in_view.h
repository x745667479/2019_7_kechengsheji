#ifndef CH_IN_VIEW_H
#define CH_IN_VIEW_H

#include <QMainWindow>
#include "datastructor.h"
namespace Ui {
class ch_in_view;
}

class ch_in_view : public QMainWindow
{
    Q_OBJECT

private slots:
     void getData(int);

     void on_pushButton_clicked();

public:
    explicit ch_in_view(QWidget *parent = nullptr);
    ~ch_in_view();

private:
    Ui::ch_in_view *ui;
    int get_target;
    VertexType *head;
    VertexType* v;
};

#endif // CH_IN_VIEW_H
