#include "bookmgr.h"
#include "ui_bookmgr.h"

BookMgr::BookMgr(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BookMgr)
{
    ui->setupUi(this);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

BookMgr::~BookMgr()
{
    delete ui;
}

void BookMgr::on_btn_add_clicked()
{

}

