#include "visitor.h"
#include "ui_visitor.h"

visitor::visitor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::visitor)
{
    ui->setupUi(this);
    ui->sub_pos->setCursor(QCursor(Qt::PointingHandCursor));
    ui->sub_time->setCursor(QCursor(Qt::PointingHandCursor));
    ui->rest->setCursor(QCursor(Qt::PointingHandCursor));
    ui->renut->setCursor(QCursor(Qt::PointingHandCursor));
    ui->view->setCursor(QCursor(Qt::PointingHandCursor));
    time_ready = false;
    pos_ready = false;
}

visitor::~visitor()
{
    delete ui;
}

void visitor::on_rest_clicked()
{
    res = new Rest(this);
    QObject::connect(this,SIGNAL(sendData(float,float,float,int)),res,SLOT(getData(float,float,float,int))); //主窗口向子窗口传递数据
    float temp_x = x;
    float temp_y = y;
    float temp_time = time;
    int num = pos;
    emit sendData(temp_x,temp_y,temp_time,num);
    res->show();
}

void visitor::on_view_clicked()
{
    vie = new View(this);
    QObject::connect(this,SIGNAL(sendData(float,float,float,int)),vie,SLOT(getData(float,float,float,int))); //主窗口向子窗口传递数据
    float temp_x = x;
    float temp_y = y;
    float temp_time = time;
    int num = pos;
    emit sendData(temp_x,temp_y,temp_time,num);
    vie->show();
}

void visitor::on_renut_clicked()
{
    ren = new Renut(this);
    QObject::connect(this,SIGNAL(sendData(float,float,float,int)),ren,SLOT(getData(float,float,float,int))); //主窗口向子窗口传递数据
    float temp_x = x;
    float temp_y = y;
    float temp_time = time;
    int num = pos;
    emit sendData(temp_x,temp_y,temp_time,num);
    ren->show();
}

void visitor::on_sub_pos_clicked()
{
    pos = ui->my_x->text().toInt();
    int temp = 0;
    ifstream iFile_pos;
    int num = 1;
    iFile_pos.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/postion.txt");
    while (iFile_pos>>temp){  //在文件中查找点的坐标
        if(temp == pos && num%3 == 1)
        {
            iFile_pos>>x>>y;
            break;  //找到坐标，赋值后返回
        }
    num++;
    }
    pos_ready = true;
}

void visitor::on_sub_time_clicked()
{
    time = ui->time->text().toFloat();
    time_ready = true;
}
