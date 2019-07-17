#ifndef RECOMMEND_H
#define RECOMMEND_H

#include <QMainWindow>

namespace Ui {
class recommend;
}

class recommend : public QMainWindow
{
    Q_OBJECT

public:
    explicit recommend(QWidget *parent = nullptr);
    ~recommend();

private:
    Ui::recommend *ui;
};

#endif // RECOMMEND_H
