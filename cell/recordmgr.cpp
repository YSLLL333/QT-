#include "recordmgr.h"
#include "ui_recordmgr.h"

RecordMgr::RecordMgr(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RecordMgr)
{
    ui->setupUi(this);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

RecordMgr::~RecordMgr()
{
    delete ui;
}
