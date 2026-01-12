#include "bookgs.h"
#include "recordmgr.h"
#include "ui_recordmgr.h"

#include "lib/sqlmgr.h"

#include <QMessageBox>

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
    m_model.setHorizontalHeaderLabels(QStringList{"图书id","图书名称","价格","类型1","类型2","类型3","数量","图片","XX","XX","XX","XX","XX","XX","XX"});
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


void RecordMgr::on_pushButton_clicked()
{
    int r = ui->tableView->currentIndex().row();
    if(r<0)
    {
        return;
    }
    auto id = m_model.item(r,2)->text();
    BookGS dlg;
    dlg.setType(true);
    dlg.setBookid(id.toInt());
    int ret = dlg.exec();
    QMessageBox::information(nullptr,"信息",ret?"归还成功":"归还失败");
    if(ret){
        initPage();
    }
}

