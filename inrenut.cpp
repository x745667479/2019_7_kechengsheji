#include "inrenut.h"
#include "ui_inrenut.h"
#include <QDebug>
#include <sstream>
inRenut::inRenut(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::inRenut)
{
    ui->setupUi(this);
    ui->submit_one->setCursor(QCursor(Qt::PointingHandCursor));
    ui->submmit_renut_dish->setCursor(QCursor(Qt::PointingHandCursor));
    ui->renut_submmit->setCursor(QCursor(Qt::PointingHandCursor));
    i = 0;
    choice = false;
    renut = new  VertexType();
    int count = 0;
    ifstream iFile_count;
    iFile_count.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/count.txt");
    iFile_count>>count;
    ui->label_13->setText(QString::number(count+1));
    iFile_count.close();

}

inRenut::~inRenut()
{
    delete ui;
}

void inRenut::on_submit_one_clicked()  //提交一次菜品
{
    string dish_name = (ui->renut_dish_name->text()).toStdString();  //把Qstring类型转换为string类型
    string dish_money = (ui->renut_dish_money->text()).toStdString();
    renut->v_renut.dish[i].renut_dish_money = stof(dish_money);   //把string类型转换为float类型
    renut->v_renut.dish[i].renut_dish_name = dish_name;
    renut->v_renut.dish[i].next = 1;
    i++;
    ui->renut_dish_name->clear();
    ui->renut_dish_money->clear();



}

void inRenut::on_submmit_renut_dish_clicked()   //确认提交一次菜品
{
    renut->v_renut.dish[i-1].next = 0;
    choice = true;
    QMessageBox::information(this,"提示","添加菜品成功");
}

void inRenut::on_renut_submmit_clicked()
{
    if(choice) {

         int count = 0;
         ofstream outFile_renut,oFile_count,outFile_pos,outFile_map;
         ifstream iFile_count,iFile_pos,iFile_map;
         iFile_count.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/count.txt");
         iFile_map.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/map.txt");//获取距离矩阵
         outFile_renut.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/resturant.txt",ofstream::app);
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
         iFile_count.close();
         outFile_map.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/map.txt");
         count++;
         oFile_count.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/count.txt");
         oFile_count<<count;
         string re_name = (ui->renut_name->text()).toStdString();
         string re_comm = (ui->renut_comm->text()).toStdString();
         string re_info = (ui->renut_info->toPlainText()).toStdString();
         string re_x = (ui->renut_x->text()).toStdString();
         string re_y = (ui->renut_y->text()).toStdString();
         string re_dire = (ui->renut_direct_num->text()).toStdString();
         string re_start = (ui->renut_start->text()).toStdString();
         string re_end = (ui->renut_end->text()).toStdString();
         renut->v_renut.renut_x = stof(re_x);
         renut->v_renut.renut_y = stof(re_y);
         renut->v_renut.renut_name = re_name;
         renut->v_renut.renut_info = re_info;
         renut->v_renut.renut_num = count;
         renut->v_renut.renut_start = stof(re_start);
         renut->v_renut.renut_end = stof(re_end);
         istringstream ist(re_dire);
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
                     charge = true;
                     iFile_pos.close();
                     break;  //找到坐标，赋值后返回
                 }
                 num++;
             }
             if(!charge){
                     QMessageBox::critical(this,"警告","连接节点输入错误！");
             }
             else {
                 len_point p1(renut->v_renut.renut_x,renut->v_renut.renut_y);
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
         outFile_renut<<count<<" "<<renut->v_renut.renut_x<<" "<<renut->v_renut.renut_y<<" "<<renut->v_renut.renut_name<<" "<<renut->v_renut.renut_info<<" ";
         outFile_renut<<renut->v_renut.renut_start<<" "<<renut->v_renut.renut_end<<" ";
         int j = 0;
         do {

             outFile_renut<<renut->v_renut.dish[j].renut_dish_name<<" "<<renut->v_renut.dish[j].renut_dish_money<<" "<<renut->v_renut.dish[j].next<<" ";
             j++;

         } while (renut->v_renut.dish[j-1].next == 1);
         renut->v_renut.renut_comm = stof(re_comm);
         outFile_renut<<renut->v_renut.renut_comm<<" ";
         renut->identify = 1;
         outFile_renut<<renut->identify<<" ";
         outFile_pos<<count<<" "<<renut->v_renut.renut_x<<" "<<renut->v_renut.renut_y<<" ";
         delete renut;

         QMessageBox::information(this,"提示","添加餐厅成功");
         ui->renut_x->clear();
         ui->renut_y->clear();
         ui->renut_name->clear();
         ui->renut_end->clear();
         ui->renut_comm->clear();
         ui->renut_info->clear();
         ui->renut_start->clear();
         ui->renut_direct_num->clear();
         oFile_count.close();
         outFile_renut.close();
         outFile_pos.close();
         outFile_map.close();
         this->close();

     }
    else {
        QMessageBox::critical(this,"警告","必须先确认添加菜品");
    }
}
