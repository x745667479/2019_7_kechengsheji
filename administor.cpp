#include "administor.h"
#include "ui_administor.h"

administor::administor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administor)
{
    ui->setupUi(this);
}

administor::~administor()
{
    delete ui;
}
