#ifndef CH_VIEW_H
#define CH_VIEW_H

#include <QMainWindow>
#include "datastructor.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QListWidget>
#include <QListWidgetItem>
#include "ch_in_view.h"

namespace Ui {
class ch_view;
}

class ch_view : public QMainWindow
{
    Q_OBJECT
signals:
    void sendData(int);

public:
    explicit ch_view(QWidget *parent = nullptr);
    ~ch_view();

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

private:
    Ui::ch_view *ui;
    ch_in_view* ch_vie;
    int target;
};

#endif // CH_VIEW_H
