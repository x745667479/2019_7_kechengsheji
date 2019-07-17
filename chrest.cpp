#include "chrest.h"
#include "ui_chrest.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;
chRest::chRest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chRest)
{
    ui->setupUi(this);
    ui->pushButton->setCursor(QCursor(Qt::PointingHandCursor));
    ui->rest->setViewMode(QListView::ListMode);//以列表方式显示
    ifstream iFile;
    int count = 0;
    int i = 0;
    iFile.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/rest.txt");
    head = new VertexType;
    r = new VertexType;
    head->next = nullptr;
    if(!iFile.is_open())
    {
        QMessageBox::critical(this,"警告","打开文件失败");
    }
    r = head;
    while (!iFile.eof()){ //从文件当中获取餐厅信息
          VertexType *temp = new VertexType;;
          iFile>>(temp->num);
          iFile>>(temp->v_rest.rest_x);
          iFile>>(temp->v_rest.rest_y);
          iFile>>(temp->v_rest.rest_zhanyong);
          iFile>>(temp->identify);
          r->next = temp;
          temp->next = nullptr;
          r = temp;
          count++;
    }
    VertexType *temp = head->next;
    while (i<count-1) {
        string num = to_string(temp->num);
        string x = to_string(temp->v_rest.rest_x).substr(0,5);//截取长度为5位
        string y = to_string(temp->v_rest.rest_y).substr(0,5);
        string zhanyong = to_string(temp->v_rest.rest_zhanyong);
        string show = "编号: "+num+"     x: "+x+"     y: "+y+"    占用状态: "+zhanyong+'\n';
        temp = temp->next;
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(show));
        ui->rest->addItem(item);
        i++;
    }
}

chRest::~chRest()
{
    delete ui;
}
void chRest::on_rest_itemClicked(QListWidgetItem *item)
{
    QString temp = item->text();
    string temp_s = temp.toStdString();
    istringstream ist(temp_s);
    string kong;
    int num;
    ist>>kong;
    ist>>num;
    target = num;

}

void chRest::on_pushButton_clicked()
{
    ch_rest = new ch_in_rest();
    QObject::connect(this,SIGNAL(sendData(int,VertexType*)),ch_rest,SLOT(getData(int,VertexType*))); //主窗口向子窗口传递数据
    int temp = target;
    emit sendData(temp,head);
    ch_rest->show();
    this->close();
}


