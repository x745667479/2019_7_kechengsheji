#include "ch_in_rest.h"
#include "ui_ch_in_rest.h"

ch_in_rest::ch_in_rest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ch_in_rest)
{
    ui->setupUi(this);
    ui->pushButton->setCursor(QCursor(Qt::PointingHandCursor));
 //   qDebug()<<"1";
}

ch_in_rest::~ch_in_rest()
{
    delete ui;
}
void ch_in_rest::getData(int temp,VertexType* head)
{
    ui->label_5->setText(QString::number(temp));
    get_target = temp;
    v = new VertexType;
    v = head->next;
    this->head = head;
    while (v != nullptr && v->num != get_target) {
        v = v->next;
    }
    ui->label_6->setText(QString("%1").arg(v->v_rest.rest_x)); //float转qstring
    ui->label_7->setText(QString("%1").arg(v->v_rest.rest_y));
    ui->lineEdit_3->setText(QString::number(v->v_rest.rest_zhanyong)); //int转qstring

}

void ch_in_rest::on_pushButton_clicked()
{
    ofstream outFile_rest;
    outFile_rest.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/rest.txt");
    v->v_rest.rest_zhanyong = (ui->lineEdit_3->text()).toInt();
    VertexType* r = head->next;
    while (r->next!=nullptr) {
            //qDebug()<<r->v_rest.rest_zhanyong;
            outFile_rest<<r->num<<" "<<r->v_rest.rest_x<<" "<<r->v_rest.rest_y<<" "<<r->v_rest.rest_zhanyong<<" "<<r->identify<<" ";
            r=r->next;
    }
    outFile_rest.close();
    QMessageBox::information(this,"提示","修改成功");

}
