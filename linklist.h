#ifndef LINKLIST_H
#define LINKLIST_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <iostream>
#include "datastructor.h"
#include "node.h"

template <class T>
class Linklist
{
public:
    Linklist();//默认构造函数
    ~Linklist();//析构函数
    int size();//链表长度
    void add(T t);//向链表中添加数据
  //  void sort_as_len(); //按照距离排序
   // void sort_as_comm();//按照评分排序

//    List();//默认构造函数
//    List(const List& ln);//拷贝构造函数
//    ~List();//析构函数
//    void add(T e);//向链表添加数据
//    void ascSort();//升序排序
//    void remove(T index);//移除某个结点
//    T find(int index);//查找结点
//    bool isEmpty();//判断是否为空
//    int size();//链表长度
//    void show();//显示链表
//    void resShow();//链表反向显示
//    void removeAll();//删除全部结点


private:
    Node<T> *head;
    Node<T> *tail;
    int length;
};

#endif // LINKLIST_H
