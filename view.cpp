#include "view.h"
#include "ui_view.h"

View::View(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);
    ui->view->setViewMode(QListView::ListMode);//以列表方式显示
    ui->sort_com->setCursor(QCursor(Qt::PointingHandCursor));
    ui->sort_len->setCursor(QCursor(Qt::PointingHandCursor));
    ui->look_info->setCursor(QCursor(Qt::PointingHandCursor));
    ui->go->setCursor(QCursor(Qt::PointingHandCursor));
    QFile file("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/view.txt");
    ifstream iFile_count;
    int max = 0;
    iFile_count.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/count.txt");
    iFile_count>>max;
    jilu = new  int[max];
    iFile_count.close();
    int count = 0;
    int i = 0;
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
          qDebug()<<temp->num;
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
     VertexType *p = head->next;//删除最后一个节点
     while (p->next->next!=nullptr) {
         p=p->next;
     }
     p->next = nullptr;

    VertexType *temp = head->next;
    while (i<count-1) {
        string num = to_string(temp->num);
        jilu[i] = temp->num;
        string x = to_string(temp->v_view.view_x).substr(0,5);//截取长度为5位
        string y = to_string(temp->v_view.view_y).substr(0,5);
        string name = temp->v_view.view_name;
        string comm = to_string(temp->v_view.view_comm).substr(0,5);
        string show = "编号: "+num+"  景点名： "+name+"   x："+x+"   y:  "+y+"  评分： "+comm+'\n';
        temp = temp->next;
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(show));
        ui->view->addItem(item);
        i++;
    }
    lengenth = i;
}

View::~View()
{
    delete ui;
}

void View::getData(float temp_x,float temp_y,float temp_time,int num)
{
    ui->label_4->setText(QString("%2").arg(temp_x));
    ui->label_6->setText(QString("%2").arg(temp_y));
    ui->label_8->setText(QString("%2").arg(temp_time));
    ui->label_10->setText(QString::number(num));
    x = temp_x;
    y = temp_y;
    time = temp_time;
    pos = num;
}

void View::on_sort_len_clicked()
{
    VertexType* temp = head->next;
    int i = 0;
    ifstream iFile_map,iFile_count;
    iFile_map.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/map.txt");
    iFile_count.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/count.txt");
    int count = 0;
    iFile_count>>count;
    float map[count][count];
    int p[count][count];
    for(int i = 0;i<count;i++) {
        for (int j =0;j<count;j++) {
            iFile_map>>map[i][j];  //读取矩阵
            p[i][j] = j;
        }
    }
    for(int k = 0; k < count; k++){
        //v为起点
        for(int v = 0 ; v < count; v++){
            //w为终点
            for(int w =0; w < count; w++){
                if(map[v][k]<65535 && map[k][w]<65535 && map[v][w]>(map[v][k] + map[k][w])){
                    map[v][w] = map[v][k] + map[k][w];//更新最小路径
                    p[v][w] = p[v][k];//更新最小路径中间顶点
                }
            }
        }
    }
    int k = 0;
    while (temp!=nullptr) {
        if((i+1)==jilu[k])  //只有编号是休息区类型的编号时，才将距离赋值给它
        {
            temp->len = map[pos-1][i];
            temp = temp->next;
            k++;
        }
        i++;

    }
    VertexType* after_sort = listMergeSort_len(head->next); //归并排序需要传入不带头节点的指针，返回的也是实际的数据而不是头节点
    temp = after_sort;
    head->next = after_sort;
    ui->view->clear();
    while (temp!=nullptr) {
        string num = to_string(temp->num);
        string x = to_string(temp->v_view.view_x).substr(0,5);//截取长度为5位
        string y = to_string(temp->v_view.view_y).substr(0,5);
        string len = to_string(temp->len).substr(0,5);
        string name = temp->v_view.view_name;
        string comm = to_string(temp->v_view.view_comm).substr(0,5);
        string show = "编号: "+num+"  景点名： "+name+"   x："+x+"   y:  "+y+"  距离："+len+"  评分： "+comm+'\n';
        temp = temp->next;
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(show));
        ui->view->addItem(item);
    }

}

void View::on_go_clicked()
{
    ifstream iFile_map,iFile_count;
    iFile_map.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/map.txt");
    iFile_count.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/count.txt");
    int count = 0;
    iFile_count>>count;
    float map[count][count];
    int p[count][count];
    for(int i = 0;i<count;i++) {
        for (int j =0;j<count;j++) {
            iFile_map>>map[i][j];  //读取矩阵
            p[i][j] = j;
        }
    }
    for(int k = 0; k < count; k++){
        //v为起点
        for(int v = 0 ; v < count; v++){
            //w为终点
            for(int w =0; w < count; w++){
                if(map[v][k]<65535 && map[k][w]<65535 && map[v][w]>(map[v][k] + map[k][w])){
                    map[v][w] = map[v][k] + map[k][w];//更新最小路径
                    p[v][w] = p[v][k];//更新最小路径中间顶点
                }
            }
        }
    }
    int v = pos-1;
    int w = target-1;
    int k = p[v][w];
    string lujing = to_string(pos)+"->"+to_string(k+1);
    while (k != p[v][k]) {
        k = p[v][k];
        lujing += "->";
        lujing += to_string(k+1);
    }
    if(k+1 != target)
    {
        lujing +="->";
        lujing += to_string(target);
    }
    QMessageBox::information(this,"提示",QString::fromStdString(lujing));
}

void View::on_view_itemClicked(QListWidgetItem *item)
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

void View::on_sort_com_clicked()
{
    VertexType* temp = head->next;
    int i = 0;
    ifstream iFile_map,iFile_count;
    iFile_map.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/map.txt");
    iFile_count.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/count.txt");
    int count = 0;
    iFile_count>>count;
    float map[count][count];
    int p[count][count];
    for(int i = 0;i<count;i++) {
        for (int j =0;j<count;j++) {
            iFile_map>>map[i][j];  //读取矩阵
            p[i][j] = j;
        }
    }
    for(int k = 0; k < count; k++){
        //v为起点
        for(int v = 0 ; v < count; v++){
            //w为终点
            for(int w =0; w < count; w++){
                if(map[v][k]<65535 && map[k][w]<65535 && map[v][w]>(map[v][k] + map[k][w])){
                    map[v][w] = map[v][k] + map[k][w];//更新最小路径
                    p[v][w] = p[v][k];//更新最小路径中间顶点
                }
            }
        }
    }
    int k = 0;
    while (temp!=nullptr) {
        if((i+1)==jilu[k])  //只有编号是休息区类型的编号时，才将距离赋值给它
        {
            temp->len = map[pos-1][i];
            temp = temp->next;
            k++;
        }
        i++;
    }
    VertexType* after_sort = listMergeSort_comm_view(head->next); //归并排序需要传入不带头节点的指针，返回的也是实际的数据而不是头节点
    temp = after_sort;
    head->next = after_sort;
    ui->view->clear();
    while (temp!=nullptr) {
        string num = to_string(temp->num);
        string x = to_string(temp->v_view.view_x).substr(0,5);//截取长度为5位
        string y = to_string(temp->v_view.view_y).substr(0,5);
        string len = to_string(temp->len).substr(0,5);
        string name = temp->v_view.view_name;
        string comm = to_string(temp->v_view.view_comm).substr(0,5);
        string show = "编号: "+num+"  景点名： "+name+"   x："+x+"   y:  "+y+"  距离："+len+"  评分： "+comm+'\n';
        temp = temp->next;
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(show));
        ui->view->addItem(item);
    }
}

void View::on_look_info_clicked()
{
    info =new view_info(this);
    QObject::connect(this,SIGNAL(sendData(int)),info,SLOT(getData(int))); //主窗口向子窗口传递数据
    emit sendData(target);
    info->show();

}
