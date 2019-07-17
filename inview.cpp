#include "inview.h"
#include "ui_inview.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <QDebug>
#include <sstream>
using namespace std;
inView::inView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::inView)
{
    ui->setupUi(this);
    ui->submint_view->setCursor(QCursor(Qt::PointingHandCursor));
    ui->submit_one_act->setCursor(QCursor(Qt::PointingHandCursor));
    ui->submit_the_act->setCursor(QCursor(Qt::PointingHandCursor));
    i = 0;
    choice = false;
    act = new  VertexType();
    int count = 0;
    ifstream iFile_count;
    iFile_count.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/count.txt");
    iFile_count>>count;
    ui->label_14->setText(QString::number(count+1));
    iFile_count.close();


}

inView::~inView()
{
    delete ui;
}

void inView::on_submit_the_act_clicked()
{
    act->v_view.act_in_view[i-1].next = 0;
    choice = true;
    QMessageBox::information(this,"提示","添加活动成功");
}

void inView::on_submit_one_act_clicked()
{

    string act_name = (ui->view_act_name->text()).toStdString();  //把Qstring类型转换为string类型
    string act_start = (ui->view_act_start->text()).toStdString();
    string act_end = (ui->view_act_end->text()).toStdString();
    string act_info = (ui->view_act_info->toPlainText()).toStdString();
    act->v_view.act_in_view[i].view_act_start = stof(act_start);   //把string类型转换为float类型
    act->v_view.act_in_view[i].view_act_end = stof(act_end);
    act->v_view.act_in_view[i].view_act_name = act_name;
    act->v_view.act_in_view[i].view_act_info = act_info;
    act->v_view.act_in_view[i].next = 1;
    i++;
    ui->view_act_name->clear();
    ui->view_act_start->clear();
    ui->view_act_end->clear();
    ui->view_act_info->clear();

}


void inView::on_submint_view_clicked()
{


   if(choice) {
        int count = 0;
        ofstream outFile_view,oFile_count,outFile_pos,outFile_map;
        ifstream iFile_count,iFile_map,iFile_pos;
        iFile_count.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/count.txt");
        outFile_view.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/view.txt",ofstream::app);
        iFile_map.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/map.txt");//获取距离矩阵;
        iFile_count>>count;
        iFile_count.close();
        float map[count+1][count+1];
        for (int i = 0;i<count;i++) {
            for (int j =0;j<count;j++) {
                iFile_map>>map[i][j];
            }
            map[i][count] = 65535;

        }
        for (int j = 0;j<=count;j++) {
            map[count][j] = 65535;
        }

        iFile_map.close();
        outFile_map.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/map.txt");
        iFile_count.close();
        count++;
        oFile_count.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/count.txt");
        oFile_count<<count;
        string view_name = (ui->view_name->text()).toStdString();
        string view_comm = (ui->view_comm->text()).toStdString();
        string view_info = (ui->view_info->toPlainText()).toStdString();
        string view_x = (ui->view_x->text()).toStdString();
        string view_y = (ui->view_y->text()).toStdString();
        string view_dire = (ui->lineEdit->text()).toStdString();
        act->v_view.view_x = stof(view_x);
        act->v_view.view_y = stof(view_y);
        act->v_view.view_name = view_name;
        act->v_view.view_num = count;
        act->v_view.view_info = view_info;

        istringstream ist(view_dire);
        int temp;
        float dire_x = 0,dire_y = 0;  //直接相连的点的坐标
        while (ist>>temp) {//开始遍历每一个直接相连的点
           // qDebug()<<"dowhile";
           // qDebug()<<"temp="<<temp;
            bool charge = false;
            int dire_num;    //直接相连的点的编号
            int num = 1;
            iFile_pos.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/postion.txt");
            while (iFile_pos>>dire_num){  //在文件中查找直接相连的点的坐标
                if(dire_num == temp && num%3 == 1)
                {
                    iFile_pos>>dire_x>>dire_y;
                    iFile_pos.close();
                    charge = true;
                    break;  //找到坐标，赋值后返回
                }
                num++;
            }
            if(!charge){
                    QMessageBox::critical(this,"警告","连接节点输入错误！");
            }
            else {
                len_point p1(act->v_view.view_x,act->v_view.view_y);
                len_point p2(dire_x,dire_y);
                len_length length(p1,p2);
              //  qDebug()<<"length = "<<length.get_length();
                map[count-1][temp-1] = length.get_length();
             //   qDebug()<<"map"<<"["<<count-1<<"]"<<"["<<temp-1<<"]="<<map[count-1][temp-1];
                map[temp-1][count-1] = length.get_length();
               // qDebug()<<"map"<<"["<<temp-1<<"]"<<"["<<count-1<<"]="<<map[temp-1][count-1];
            }

        }
        map[count-1][count-1] = 0;

        for (int i = 0;i<count;i++) {  //把修改后的矩阵写回文件
            for (int j = 0;j<count;j++) {
               outFile_map<<map[i][j]<<" ";
              //  qDebug()<<map[i][j]<<" ";

            }
            outFile_map<<endl;

        }
        iFile_pos.close();
        outFile_pos.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/postion.txt",ofstream::app);
        outFile_view<<count<<" "<<act->v_view.view_x<<" "<<act->v_view.view_y<<" "<<act->v_view.view_name<<" "<<act->v_view.view_info<<" ";
        int j = 0;
        do {

            outFile_view<<act->v_view.act_in_view[j].view_act_start<<" "<<act->v_view.act_in_view[j].view_act_end<<" ";
            outFile_view<<act->v_view.act_in_view[j].view_act_info<<" "<<act->v_view.act_in_view[j].view_act_name<<" ";
            outFile_view<<act->v_view.act_in_view[j].next<<" ";
            j++;

        } while (act->v_view.act_in_view[j-1].next == 1);
        act->v_view.view_comm = stof(view_comm);
        outFile_view<<act->v_view.view_comm<<" ";
        outFile_pos<<count<<" "<<act->v_view.view_x<<" "<<act->v_view.view_y<<" ";
        act->identify = 0;
        outFile_view<<act->identify<<" ";
        delete act;
        outFile_view.close();
        outFile_pos.close();
        oFile_count.close();
        outFile_map.close();

        QMessageBox::information(this,"提示","添加景点成功");
        ui->view_x->clear();
        ui->view_y->clear();
        ui->view_comm->clear();
        ui->view_info->clear();
        ui->view_name->clear();
        ui->lineEdit->clear();
        this->close();



    }
   else {
        QMessageBox::critical(this,"错误","请确认活动已经添加完毕");
   }
}
