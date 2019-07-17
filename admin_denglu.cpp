#include "admin_denglu.h"
#include "ui_admin_denglu.h"

admin_denglu::admin_denglu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::admin_denglu)
{
    ui->setupUi(this);
    ui->admin_denglu_2->setCursor(QCursor(Qt::PointingHandCursor));
    ui->admin_tuichu->setCursor(QCursor(Qt::PointingHandCursor));
}

admin_denglu::~admin_denglu()
{
    delete ui;
}

void admin_denglu::on_admin_denglu_2_clicked()
{
    if(ui->username->text()==tr("adminstor") && ui->passward->text()==tr("123456")){  //进入管理员界面
        admin = new admin_ui(this);
        admin->show();
        this->close();
       }
    else {
             //弹出错误警告框
        QMessageBox::critical(this,"警告","用户名或密码错误！");
    }
}
