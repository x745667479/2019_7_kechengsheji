#include "mainwindow.h"
#include <QApplication>
#include "datastructor.h"
#include "admin.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
