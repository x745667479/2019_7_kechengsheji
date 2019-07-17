#include "admin_ui.h"
#include "ui_admin_ui.h"

admin_ui::admin_ui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::admin_ui)
{
    ui->setupUi(this);
    ui->inView->setCursor(QCursor(Qt::PointingHandCursor));
    ui->inRest->setCursor(QCursor(Qt::PointingHandCursor));
    ui->inRenut->setCursor(QCursor(Qt::PointingHandCursor));
    ui->chRest->setCursor(QCursor(Qt::PointingHandCursor));
    ui->chRenut->setCursor(QCursor(Qt::PointingHandCursor));
    ui->chView->setCursor(QCursor(Qt::PointingHandCursor));
}

admin_ui::~admin_ui()
{
    delete ui;
}

void admin_ui::on_inRenut_clicked()
{
    inrenut = new inRenut(this);
    inrenut->show();

}

void admin_ui::on_inView_clicked()
{
    inview = new inView(this);
    inview->show();
}

void admin_ui::on_inRest_clicked()
{
    inrest = new inRest(this);
    inrest->show();
}

void admin_ui::on_chRenut_clicked()
{
    chrenut = new chRenut(this);
    chrenut->show();
}

void admin_ui::on_chView_clicked()
{
    chview = new ch_view(this);
    chview->show();
}

void admin_ui::on_chRest_clicked()
{
    chrest = new chRest(this);
    chrest->show();
}
