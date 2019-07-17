#include "inrest.h"
#include "ui_inrest.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <qdebug.h>
using namespace std;
inRest::inRest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::inRest)
{
    ui->setupUi(this);
    ui->submit_rest->setCursor(QCursor(Qt::PointingHandCursor));
    rest = new  VertexType();
    int count = 0;
    ifstream iFile_count;
    iFile_count.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/count.txt");
    iFile_count>>count;
    ui->label_6->setText(QString::number(count+1));
    iFile_count.close();

}

inRest::~inRest()
{
    delete ui;
}



void inRest::on_submit_rest_clicked()
{

    int count;
    ofstream outFile_rest,outFile_pos,outFile_map,oFile_count;
    ifstream iFile_count,iFile_pos,iFile_map;
    iFile_count.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/count.txt");
    iFile_map.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/map.txt");//获取距离矩阵
    outFile_rest.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/rest.txt",ofstream::app);
    iFile_count>>count;
    float map[count+1][count+1];
    for (int i = 0;i<count;i++) {
        for (int j =0;j<count;j++) {
            iFile_map>>map[i][j];
        }
        map[i][count] = 65535;  //把新增的那一列赋值为inf

    }
    for (int j = 0;j<=count;j++) {
        map[count][j] = 65535;  //把新增的那一行赋值为inf
    }
    iFile_map.close();
    outFile_map.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/map.txt");  //此文件必须在获取完原矩阵后打开，否则原矩阵信息丢失。
    count++;   //录入这个后，编号数加一
    iFile_count.close();
    oFile_count.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/count.txt");
    oFile_count<<count;
    string rest_x = (ui->rest_x->text()).toStdString();  //把Qstring类型转换为string类型
    string rest_y = (ui->rest_y->text()).toStdString();
    string rest_dire = (ui->lineEdit->text()).toStdString();  //获得与其直接相连的节点编号
    rest->v_rest.rest_x = stof(rest_x);   //把string类型转换为float类型
    rest->v_rest.rest_y = stof(rest_y);
    rest->v_rest.rest_zhanyong = 0;
    rest->v_rest.rest_num = count;
    rest->identify = 2;

    //提取与其直接相连的节点，并在矩阵上做出修改
    //1.提取出与其直接相连的编号
    //2.在poison文件当中查找出相连的编号对应的坐标
    //3.用添加点的坐标与相连点的坐标计算出两者之间的距离
    istringstream ist(rest_dire);
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
            if(dire_num == temp && num%3 == 1)  //恰好是第1，4，7，。。。。的位置才是编号
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
            len_point p1(rest->v_rest.rest_x,rest->v_rest.rest_y);
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

    outFile_pos.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/postion.txt",ofstream::app);
    //把添加的信息写入文件
    outFile_rest<<rest->v_rest.rest_num<<" "<<rest->v_rest.rest_x<<" "<<rest->v_rest.rest_y<<" "<<rest->v_rest.rest_zhanyong<<" "<<rest->identify<<" ";
    outFile_pos<<count<<" "<<rest->v_rest.rest_x<<" "<<rest->v_rest.rest_y<<" ";
    outFile_pos.close();
    outFile_rest.close();
    outFile_map.close();
    oFile_count.close();
    delete  rest;
    QMessageBox::information(this,"提示","添加休息区成功");
    ui->rest_x->clear();
    ui->rest_y->clear();
    ui->lineEdit->clear();
    this->close();
    //存入文件的格式为：x坐标+空格+y坐标+占用标识+空格+类型标识+空格.


}
