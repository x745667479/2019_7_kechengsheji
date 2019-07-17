#include "renut_info.h"
#include "ui_renut_info.h"

renut_info::renut_info(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::renut_info)
{
    ui->setupUi(this);
}

renut_info::~renut_info()
{
    delete ui;
}

void renut_info::getData(int num)
{
    target = num;
    QFile file("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/resturant.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this,"警告","打开文件失败");
    }
    QTextStream iFile(&file);
    VertexType *temp = new VertexType;
    iFile.setCodec("utf-8");  //处理中文乱码问题
     while (!iFile.atEnd()){ //从文件当中获取餐厅信息
          iFile>>(temp->num);
          iFile>>(temp->v_renut.renut_x);
          iFile>>(temp->v_renut.renut_y);
          QString renut_name;
          iFile>>renut_name;
          temp->v_renut.renut_name = renut_name.toStdString();
          QString renut_info;
          iFile>>renut_info;
          temp->v_renut.renut_info = renut_info.toStdString();
          iFile>>(temp->v_renut.renut_start);
          iFile>>(temp->v_renut.renut_end);
          int j = 0;
          do {
               QString dish_name;
               iFile>>dish_name;
               temp->v_renut.dish[j].renut_dish_name = dish_name.toStdString();
               iFile>>temp->v_renut.dish[j].renut_dish_money;
               iFile>>temp->v_renut.dish[j].next;
               j++;
              } while (temp->v_renut.dish[j-1].next == 1);
          iFile>>temp->v_renut.renut_comm;
          iFile>>temp->identify;
          if(temp->num == target)
              break;
   }
   qDebug()<<target;
   qDebug()<<temp->num;
   ui->label_2->setText(QString::number(temp->num));
   ui->label_4->setText(QString::fromStdString(temp->v_renut.renut_name));
   ui->label_7->setText(QString("%1").arg(temp->v_renut.renut_x));
   ui->label_9->setText(QString("%1").arg(temp->v_renut.renut_y));
   ui->label_11->setText(QString("%1").arg(temp->v_renut.renut_start));
   ui->label_13->setText(QString("%1").arg(temp->v_renut.renut_end));
   ui->label_15->setText(QString("%1").arg(temp->v_renut.renut_comm));
   ui->textEdit->setText(QString::fromStdString(temp->v_renut.renut_info));
   int j = 0;
   do {
       string name = (temp->v_renut.dish[j].renut_dish_name);
       string money = to_string(temp->v_renut.dish[j].renut_dish_money).substr(0,5);
       string show = "菜名："+name+" 价格："+money+'\n';
       QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(show));
       ui->listWidget->addItem(item);
       j++;
       }while (temp->v_renut.dish[j-1].next == 1);
}
