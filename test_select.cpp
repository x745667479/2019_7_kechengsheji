#include <iostream>
#include <string>
#include <QString>
#include <stdio.h>
using namespace std;
const int len=50;
void ch_the_map(QString str)
{

    char select[] = "";
    char select_point[] = "";
    string select_temp = str.toStdString();
    strcpy(select,select_temp.c_str());
    int i = 0;
    int k = 0;
    while (select[i]!='\0') {
        select_point[k] = select[i];
        i = i+2;
    }
    while (select_point[k]!='\0') {
        cout<<select_point[k];
        k++;

    }



}
