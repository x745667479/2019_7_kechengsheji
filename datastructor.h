#ifndef DATASTRUCTOR_H
#define DATASTRUCTOR_H
#include <iostream>
#include <fstream>
#include <vector>
#include <qtextcodec.h>
#include <QString>
#include <QFile>
#include <sstream>
#include <QDebug>
#include <QMessageBox>
#include "len_point.h"

const int MAX_SIZE = 255;
using namespace std;


typedef struct{
    float view_act_start;  //活动的开始时间
    float view_act_end;  //活动的结束时间
    string view_act_info;  //活动的介绍信息
    string view_act_name;  //活动的名称
    int next;


}view_act; //景点的活动

typedef struct{
    float view_num;       //景点的编号
    float view_x,view_y;           //景点的横纵坐标
    string view_name;   //景点的名称
    string view_info;   //景点的介绍
    view_act act_in_view[MAX_SIZE];     //景点的活动
    float view_comm;    //景点的游客评价
    float view_len;     //景点的距离
    float view_comp;    //景点的综合评价


}view;   //景点


typedef struct{

    string renut_dish_name;    //菜品的名字
    float renut_dish_money;    //菜品的价格
    int next;


}renut_dish; //餐厅的菜品


typedef struct{

    int renut_num;      //餐厅的编号
    float renut_x,renut_y;
    string renut_name;   //餐厅的名字
    string renut_info;    //餐厅的介绍
    renut_dish dish[MAX_SIZE];  //餐厅的推荐菜品
    float renut_comm;     //餐厅的游客评价
    float renut_len;       //餐厅的距离
    float renut_comp;       //餐厅的综合评价
    float renut_start;   //餐厅的开始营业时间
    float renut_end;      //餐厅的结束营业时间



}renut;  //餐厅

typedef struct{

    float rest_num;
    float rest_x,rest_y;
    int rest_zhanyong;

}rest;  //休息区

typedef  struct VertexType{
  int num;   //顶点编号
  view v_view;  //景点类型
  renut v_renut;  //餐厅类型
  rest v_rest;  //休息区类型
  int identify;  //区分标识，0表示景点，1表示餐厅，2表示休息区。
  VertexType *next;
  float len = 0;

}VertexType;   //顶点的类型

typedef  struct{
    VertexType vex[MAX_SIZE];
    float arc[MAX_SIZE][MAX_SIZE];
    int vernum,arcnum;

}Map;   //图的类型


#endif // DATASTRUCTOR_H
