#include "bookmgr.h"
#include "ui_bookmgr.h"
#include"lib/sqlmgr.h"
BookMgr::BookMgr(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BookMgr)
{
    ui->setupUi(this);
    ui->tableView->setModel(&m_model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

BookMgr::~BookMgr()
{
    delete ui;
}

void BookMgr::initPage(QString strCondition)
{
    //刷新、初始化

    auto l=SqlMgr::getinstance()->getBooks(strCondition);
    m_model.clear();
    m_model.setHorizontalHeaderLabels(QStringList{"图书id","图书名称","价格","类型1","类型2","类型3","数量","图片"});
    for(int i =0;i<l.size();i++){    QList<QStandardItem*> items;

        for(int j=0;j<l[i].size();j++){
            items.append(new QStandardItem(l[i][j]));
        }
        m_model.appendRow(items);
    }
}

void BookMgr::on_btn_add_clicked()
{

}


void BookMgr::on_btn_update_clicked()
{

}


void BookMgr::on_btn_del_clicked()
{

}


void BookMgr::on_btn_brw_clicked()
{

}


void BookMgr::on_btn_rtn_clicked()
{

}


void BookMgr::on_le_srch_textChanged(const QString &arg1)
{

}

