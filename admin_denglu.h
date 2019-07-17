#ifndef ADMIN_DENGLU_H
#define ADMIN_DENGLU_H

#include <QMainWindow>
#include "admin_ui.h"
#include <QMessageBox>
namespace Ui {
class admin_denglu;
}

class admin_denglu : public QMainWindow
{
    Q_OBJECT

public:
    explicit admin_denglu(QWidget *parent = nullptr);
    ~admin_denglu();

private slots:
    void on_admin_denglu_2_clicked();

private:
    Ui::admin_denglu *ui;
    admin_ui *admin;
};

#endif // ADMIN_DENGLU_H
