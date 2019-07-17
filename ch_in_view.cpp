#include "ch_in_view.h"
#include "ui_ch_in_view.h"

ch_in_view::ch_in_view(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ch_in_view)
{
    ui->setupUi(this);
    ui->pushButton->setCursor(QCursor(Qt::PointingHandCursor));
}

ch_in_view::~ch_in_view()
{
    delete ui;
}
void ch_in_view::getData(int temp)
{
    ui->label_3->setText(QString::number(temp));
    get_target = temp;
    QFile file("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/view.txt");
    int count = 0;
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

     v = head->next;
     while (v->num != temp) {
         v=v->next;
     }

    ui->label_3->setText(QString::number(temp));
    ui->lineEdit->setText(QString::fromStdString(v->v_view.view_name));
    ui->lineEdit_2->setText(QString("%1").arg(v->v_view.view_comm));//float转qstring
    ui->textEdit->setText(QString::fromStdString(v->v_view.view_info));



}

void ch_in_view::on_pushButton_clicked()
{
    ofstream outFile_view;
    outFile_view.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/view.txt");
    v->v_view.view_name = (ui->lineEdit->text()).toStdString();
    v->v_view.view_comm = stof((ui->lineEdit_2->text()).toStdString());
    v->v_view.view_info = (ui->textEdit->toPlainText()).toStdString();
    VertexType* act = head->next;
    while (act->next!=nullptr) {
        outFile_view<<act->num<<" "<<act->v_view.view_x<<" "<<act->v_view.view_y<<" "<<act->v_view.view_name<<" "<<act->v_view.view_info<<" ";
        int j = 0;
        do {
            outFile_view<<act->v_view.act_in_view[j].view_act_start<<" "<<act->v_view.act_in_view[j].view_act_end<<" ";
            outFile_view<<act->v_view.act_in_view[j].view_act_info<<" "<<act->v_view.act_in_view[j].view_act_name<<" ";
            outFile_view<<act->v_view.act_in_view[j].next<<" ";
            j++;

        } while (act->v_view.act_in_view[j-1].next == 1);
        outFile_view<<act->v_view.view_comm<<" ";
        outFile_view<<act->identify<<" ";
        act = act->next;
    }
    outFile_view.close();
    QMessageBox::information(this,"提示","修改成功");
}
