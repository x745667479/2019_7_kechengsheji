#include "view_info.h"
#include "ui_view_info.h"
#include "datastructor.h"
view_info::view_info(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::view_info)
{
    ui->setupUi(this);
}

view_info::~view_info()
{
    delete ui;
}

void view_info::getData(int tget)
{

    target = tget;
    ui->label_2->setText(QString::number(target));
    QFile file("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/view.txt");
    ifstream iFile_count;
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this,"警告","打开文件失败");
    }
    QTextStream iFile(&file);
    iFile.setCodec("utf-8");  //处理中文乱码问题
     VertexType *temp = new VertexType;
     while (!iFile.atEnd()){ //从文件当中获取餐厅信息
          iFile>>(temp->num);
          iFile>>(temp->v_view.view_x);
          iFile>>(temp->v_view.view_y);
          QString view_name;
          iFile>>view_name;
          temp->v_view.view_name = view_name.toStdString();
          QString view_info;
          iFile>>view_info;
          temp->v_view.view_info = view_info.toStdString();
          int j = 0;
          do {

               iFile>>temp->v_view.act_in_view[j].view_act_start;
               iFile>>temp->v_view.act_in_view[j].view_act_end;
               QString act_info;
               iFile>>act_info;
               temp->v_view.act_in_view[j].view_act_info = act_info.toStdString();
               QString act_name;
               iFile>>act_name;
               temp->v_view.act_in_view[j].view_act_name = act_name.toStdString();
               iFile>>temp->v_view.act_in_view[j].next;
               j++;
              } while (temp->v_view.act_in_view[j-1].next == 1);
          iFile>>temp->v_view.view_comm;
          iFile>>temp->identify;
          if(temp->num == target)
              break;
   }
   ui->label_4->setText(QString::fromStdString(temp->v_view.view_name));
   ui->textEdit->setText(QString::fromStdString(temp->v_view.view_info));
   ui->label_8->setText(QString("%1").arg(temp->v_view.view_x));
   ui->label_10->setText(QString("%1").arg(temp->v_view.view_y));
   ui->label_12->setText(QString("%1").arg(temp->v_view.view_comm));
   int j = 0;
   do {
       string name = (temp->v_view.act_in_view[j].view_act_name);
       string start = (to_string(temp->v_view.act_in_view[j].view_act_start)).substr(0,5);
       string end = (to_string(temp->v_view.act_in_view[j].view_act_end)).substr(0,5);
       string show = "活动名称："+name+" 开始时间："+start+" 结束时间："+end+'\n';
       QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(show));
       ui->listWidget->addItem(item);
       j++;
       }while (temp->v_view.act_in_view[j-1].next == 1);

}
