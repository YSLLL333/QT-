#ifndef USERMGR_H
#define USERMGR_H

#include <QWidget>

namespace Ui {
class UserMgr;
}

class UserMgr : public QWidget
{
    Q_OBJECT

public:
    explicit UserMgr(QWidget *parent = nullptr);
    ~UserMgr();

private:
    Ui::UserMgr *ui;
};

#endif // USERMGR_H
