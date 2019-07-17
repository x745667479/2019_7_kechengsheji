#ifndef VIEW_INFO_H
#define VIEW_INFO_H

#include <QMainWindow>

namespace Ui {
class view_info;
}

class view_info : public QMainWindow
{
    Q_OBJECT
private slots:
    void getData(int);
public:
    explicit view_info(QWidget *parent = nullptr);
    ~view_info();

private:
    Ui::view_info *ui;
    int target;
};

#endif // VIEW_INFO_H
