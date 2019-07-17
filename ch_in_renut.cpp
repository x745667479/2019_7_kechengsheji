#include "ch_in_renut.h"
#include "ui_ch_in_renut.h"

ch_in_renut::ch_in_renut(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ch_in_renut)
{
    ui->setupUi(this);
    ui->pushButton->setCursor(QCursor(Qt::PointingHandCursor));
}

ch_in_renut::~ch_in_renut()
{
    delete ui;
}
void ch_in_renut::getData(int temp)
{
    ui->label_3->setText(QString::number(temp));
    get_target = temp;
    QFile file("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/resturant.txt");
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
    ui->lineEdit->setText(QString::fromStdString(v->v_renut.renut_name));
    ui->lineEdit_2->setText(QString("%1").arg(v->v_renut.renut_start));//float转qstring
    ui->lineEdit_3->setText(QString("%1").arg(v->v_renut.renut_end));
    ui->textEdit->setText(QString::fromStdString(v->v_renut.renut_info));



}

void ch_in_renut::on_pushButton_clicked()
{
    ofstream outFile_renut;
    outFile_renut.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/resturant.txt");
    v->v_renut.renut_name = (ui->lineEdit->text()).toStdString();
    v->v_renut.renut_start = stof((ui->lineEdit_2->text()).toStdString());
    v->v_renut.renut_end = stof((ui->lineEdit_3->text()).toStdString());
    v->v_renut.renut_info = (ui->textEdit->toPlainText()).toStdString();
    VertexType* renut = head->next;
    while (renut->next!=nullptr) {
        outFile_renut<<renut->num<<" "<<renut->v_renut.renut_x<<" "<<renut->v_renut.renut_y<<" "<<renut->v_renut.renut_name<<" "<<renut->v_renut.renut_info<<" ";
        outFile_renut<<renut->v_renut.renut_start<<" "<<renut->v_renut.renut_end<<" ";
        int j = 0;
        do {

            outFile_renut<<renut->v_renut.dish[j].renut_dish_name<<" "<<renut->v_renut.dish[j].renut_dish_money<<" "<<renut->v_renut.dish[j].next<<" ";
            j++;

        } while (renut->v_renut.dish[j-1].next == 1);
        outFile_renut<<renut->v_renut.renut_comm<<" ";
        renut->identify = 1;
        outFile_renut<<renut->identify<<" ";
        renut=renut->next;
    }
    outFile_renut.close();
    QMessageBox::information(this,"提示","修改成功");
}
