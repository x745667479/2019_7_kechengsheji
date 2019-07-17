#ifndef ADMINISTOR_H
#define ADMINISTOR_H

#include <QDialog>

namespace Ui {
class administor;
}

class administor : public QDialog
{
    Q_OBJECT

public:
    explicit administor(QWidget *parent = nullptr);
    ~administor();

private:
    Ui::administor *ui;
};

#endif // ADMINISTOR_H
