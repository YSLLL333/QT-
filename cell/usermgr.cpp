#include "usermgr.h"
#include "ui_usermgr.h"

UserMgr::UserMgr(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserMgr)
{
    ui->setupUi(this);
}

UserMgr::~UserMgr()
{
    delete ui;
}
