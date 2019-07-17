#include "denglu.h"
#include "ui_denglu.h"
#include <QMessageBox>
denglu::denglu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::denglu)
{
    ui->setupUi(this);

}

denglu::~denglu()
{
    delete ui;
}



void denglu::on_admin_denglu_clicked()
{
    if(ui->username->text()==tr("adminstor")&&ui->passward->text()==tr("123456")){  //进入管理员界面
        admin_ui = new administor(this);
        admin_ui->setModal(false);
        admin_ui->show();
       }
    else {
             //弹出错误警告框
        QMessageBox::critical(this,"警告","用户名或密码错误！");
    }
}
