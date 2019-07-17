#ifndef RENUT_INFO_H
#define RENUT_INFO_H

#include <QMainWindow>
#include "datastructor.h"

namespace Ui {
class renut_info;
}

class renut_info : public QMainWindow
{
    Q_OBJECT
private slots:
    void getData(int);
public:
    explicit renut_info(QWidget *parent = nullptr);
    ~renut_info();

private:
    Ui::renut_info *ui;
    int target;
};

#endif // RENUT_INFO_H
