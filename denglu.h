#ifndef DENGLU_H
#define DENGLU_H

#include <QDialog>
#include "administor.h"
namespace Ui {
class denglu;
}

class denglu : public QDialog
{
    Q_OBJECT

public:
    explicit denglu(QWidget *parent = nullptr);
    ~denglu();

private slots:



    void on_admin_denglu_clicked();

private:
    Ui::denglu *ui;
    administor *admin_ui;

};

#endif // DENGLU_H
