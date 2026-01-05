#include "recordmgr.h"
#include "ui_recordmgr.h"

#include "lib/sqlmgr.h"

RecordMgr::RecordMgr(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RecordMgr)
{
    ui->setupUi(this);
    ui->tableView->setModel(&m_model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

RecordMgr::~RecordMgr()
{
    delete ui;
}

void RecordMgr::initPage(QString strCondition)
{
    auto l=SqlMgr::getinstance()->getRecord(strCondition);
    m_model.clear();
    m_model.setHorizontalHeaderLabels(QStringList{"图书id","图书名称","价格","类型1","类型2","类型3","数量","图片"});
    for(int i =0;i<l.size();i++){    QList<QStandardItem*> items;

        for(int j=0;j<l[i].size();j++){
            items.append(new QStandardItem(l[i][j]));
        }
        m_model.appendRow(items);
    }
}

void RecordMgr::on_le_srch_textChanged(const QString &arg1)
{
    initPage(arg1);
}


void RecordMgr::on_btn_clr_clicked()
{
    SqlMgr::getinstance()->ClrRecord();
    initPage();
}

