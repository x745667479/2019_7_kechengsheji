#include "rest.h"
#include "ui_rest.h"

Rest::Rest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Rest)
{
    ui->setupUi(this);
    ui->sort_len->setCursor(QCursor(Qt::PointingHandCursor));
    ui->rest->setViewMode(QListView::ListMode);//以列表方式显示
    ui->go->setCursor(QCursor(Qt::PointingHandCursor));
    ifstream iFile,iFile_count;
    int count = 0;
    int max = 0;
    iFile_count.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/count.txt");
    iFile_count>>max;
    iFile_count.close();
    jilu = new  int[max];
    int i = 0;
    iFile.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/rest.txt");
    head = new VertexType;
    r = new VertexType;
    head->next = nullptr;
    if(!iFile.is_open())
    {
        QMessageBox::critical(this,"警告","打开文件失败");
    }
    r = head;
    while (!iFile.eof()){ //从文件当中获取餐厅信息
          VertexType *temp = new VertexType;;
          iFile>>(temp->num);
          iFile>>(temp->v_rest.rest_x);
          iFile>>(temp->v_rest.rest_y);
          iFile>>(temp->v_rest.rest_zhanyong);
          iFile>>(temp->identify);
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
        string x = to_string(temp->v_rest.rest_x).substr(0,5);//截取长度为5位
        string y = to_string(temp->v_rest.rest_y).substr(0,5);
        string zhanyong = to_string(temp->v_rest.rest_zhanyong);
        string show = "编号: "+num+"     x: "+x+"     y: "+y+"    占用状态: "+zhanyong+'\n';
        temp = temp->next;
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(show));
        ui->rest->addItem(item);
        i++;
    }
    lengenth = i;

}

Rest::~Rest()
{
    delete ui;
}

void Rest::getData(float temp_x,float temp_y,float temp_time,int num)
{
    ui->label_5->setText(QString("%2").arg(temp_x));
    ui->label_6->setText(QString("%2").arg(temp_y));
    ui->label_8->setText(QString("%2").arg(temp_time));
    ui->label_10->setText(QString::number(num));
    x = temp_x;
    y = temp_y;
    time = temp_time;
    pos = num;


}

void Rest::on_sort_len_clicked()
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
    VertexType* after_sort = listMergeSort_len(head->next);//归并排序需要传入不带头节点的指针，返回的也是实际的数据而不是头节点
    temp = after_sort;
    head->next = after_sort;
    ui->rest->clear();
    while (temp!=nullptr) {
        string num = to_string(temp->num);
        string x = to_string(temp->v_rest.rest_x).substr(0,5);//截取长度为5位
        string y = to_string(temp->v_rest.rest_y).substr(0,5);
        string zhanyong = to_string(temp->v_rest.rest_zhanyong);
        string len = to_string(temp->len).substr(0,5);
        string show = "编号: "+num+"     x: "+x+"     y: "+y+"    占用状态: "+zhanyong+"距离："+len+"\n";
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(show));
        ui->rest->addItem(item);
        temp = temp->next;
    }

}

void Rest::on_go_clicked()
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
    if( k+1 != target)
    {
        lujing +="->";
        lujing += to_string(target);
    }
    QMessageBox::information(this,"提示",QString::fromStdString(lujing));

}

void Rest::on_rest_itemClicked(QListWidgetItem *item)
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
