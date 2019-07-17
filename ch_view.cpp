#include "ch_view.h"
#include "ui_ch_view.h"

ch_view::ch_view(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ch_view)
{
    ui->setupUi(this);
    ui->listWidget->setViewMode(QListView::ListMode);//以列表方式显示
    ui->pushButton->setCursor(QCursor(Qt::PointingHandCursor));
    QFile file("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/view.txt");
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
          r->next = temp;
          temp->next = nullptr;
          r = temp;
          count++;
   }

    VertexType *temp = head->next;
    while (i<count-1) {

        string num = to_string(temp->num);
        string x = to_string(temp->v_view.view_x).substr(0,5);//截取长度为5位
        string y = to_string(temp->v_view.view_y).substr(0,5);
        string name = temp->v_view.view_name;
        string show = "编号: "+num+"  景点名： "+name+"   x："+x+"   y:  "+y+'\n';
        temp = temp->next;
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(show));
        ui->listWidget->addItem(item);
        i++;
    }
}


ch_view::~ch_view()
{
    delete ui;
}

void ch_view::on_listWidget_itemClicked(QListWidgetItem *item)
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

void ch_view::on_pushButton_clicked()
{
    ch_vie = new ch_in_view();
    QObject::connect(this,SIGNAL(sendData(int)),ch_vie,SLOT(getData(int))); //主窗口向子窗口传递数据
    int temp = target;
    emit sendData(temp);
    ch_vie->show();
    this->close();
}
