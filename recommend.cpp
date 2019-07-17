#include "recommend.h"
#include "ui_recommend.h"

recommend::recommend(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::recommend)
{
    ui->setupUi(this);
}

recommend::~recommend()
{
    delete ui;
}
