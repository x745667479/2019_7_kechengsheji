#include "chrenut.h"
#include "ui_chrenut.h"

chRenut::chRenut(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chRenut)
{
    ui->setupUi(this);
 //   QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));
    ui->listWidget->setViewMode(QListView::ListMode);//以列表方式显示
    ui->pushButton->setCursor(QCursor(Qt::PointingHandCursor));
    QFile file("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/resturant.txt");
    int count = 0;
    int i = 0;
    VertexType *head;
    VertexType *r;
    head = new VertexType;
    r = new VertexType;
    head->next = nullptr;
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this,"警告","打开文件失败");
    }
    r = head;
    QTextStream iFile(&file);
    iFile.setCodec("utf-8");  //处理中文乱码问题
     while (!iFile.atEnd()){ //从文件当中获取餐厅信息
          VertexType *temp = new VertexType;
          iFile>>(temp->num);
        //  qDebug()<<temp->num;
          iFile>>(temp->v_renut.renut_x);
      //  qDebug()<<temp->v_renut.renut_x;
          iFile>>(temp->v_renut.renut_y);
      //    qDebug()<<temp->v_renut.renut_y;
          QString renut_name;
          iFile>>renut_name;
          temp->v_renut.renut_name = renut_name.toStdString();
   //       qDebug()<<temp->v_renut.renut_name.c_str();
          QString renut_info;
          iFile>>renut_info;
          temp->v_renut.renut_info = renut_info.toStdString();
//        /  qDebug()<<temp->v_renut.renut_info.c_str();
          iFile>>(temp->v_renut.renut_start);
          iFile>>(temp->v_renut.renut_end);
          int j = 0;
          do {
               QString dish_name;
               iFile>>dish_name;
               temp->v_renut.dish[j].renut_dish_name = dish_name.toStdString();
             //  qDebug()<<temp->v_renut.dish[j].renut_dish_name.c_str();
               iFile>>temp->v_renut.dish[j].renut_dish_money;
             //  qDebug()<<temp->v_renut.dish[j].renut_dish_money;
               iFile>>temp->v_renut.dish[j].next;
               j++;
              } while (temp->v_renut.dish[j-1].next == 1);
          iFile>>temp->v_renut.renut_comm;
          iFile>>temp->identify;
          r->next = temp;
          temp->next = nullptr;
          r = temp;
          count++;
   }

    VertexType *temp = head->next;
    while (i<count-1) {

        string num = to_string(temp->num);
        string x = to_string(temp->v_renut.renut_x).substr(0,5);//截取长度为5位
        string y = to_string(temp->v_renut.renut_y).substr(0,5);
        string name = temp->v_renut.renut_name;
        string show = "编号: "+num+"  店名： "+name+"   x："+x+"   y:  "+y+'\n';
        temp = temp->next;
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(show));
        ui->listWidget->addItem(item);
        i++;
    }
}

chRenut::~chRenut()
{
    delete ui;
}

void chRenut::on_listWidget_itemClicked(QListWidgetItem *item)
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

void chRenut::on_pushButton_clicked()
{
    ch_renut = new ch_in_renut();
    QObject::connect(this,SIGNAL(sendData(int)),ch_renut,SLOT(getData(int))); //主窗口向子窗口传递数据
    int temp = target;
    emit sendData(temp);
    ch_renut->show();
    this->close();
}
