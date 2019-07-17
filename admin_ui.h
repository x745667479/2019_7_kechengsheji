#ifndef ADMIN_UI_H
#define ADMIN_UI_H

#include <QMainWindow>
#include "inrenut.h"
#include "inrest.h"
#include "inview.h"
#include "chrenut.h"
#include "chrest.h"
#include "ch_view.h"
namespace Ui {
class admin_ui;
}

class admin_ui : public QMainWindow
{
    Q_OBJECT

public:
    explicit admin_ui(QWidget *parent = nullptr);
    ~admin_ui();

private slots:
    void on_inRenut_clicked();

    void on_inView_clicked();

    void on_inRest_clicked();

    void on_chRenut_clicked();

    void on_chView_clicked();

    void on_chRest_clicked();

private:
    Ui::admin_ui *ui;
    inRenut *inrenut;
    inRest *inrest;
    inView *inview;
    chRest *chrest;
    chRenut *chrenut;
    ch_view *chview;


};

#endif // ADMIN_UI_H
