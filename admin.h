#ifndef ADMIN_H
#define ADMIN_H

#include "datastructor.h"
#include <iostream>
#include <fstream>
using namespace std;
bool denglu(string user_name,string pass_ward) //管理员登陆界面
{
    string a[5];
    int i=0;
    ifstream infile;
    infile.open("D:/CPPPPPPPPPPPPPPPPP/softwaer_design/admin.txt",ios::in);
    while (!infile.eof())
    {
        getline(infile,a[i],'\n');
        i++;

    }
    infile.close();
    if(user_name == a[0] && pass_ward == a[1])
        return true;
    else {
        return false;
    }
}

#endif // ADMIN_H
