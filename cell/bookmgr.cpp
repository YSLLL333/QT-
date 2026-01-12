#include "bookmgr.h"
#include "ui_bookmgr.h"
#include"lib/sqlmgr.h"
#include "bookau.h"
#include <QMessageBox>
#include "bookgs.h"

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
    BookAU dlg;
    dlg.exec();
    initPage();
}


void BookMgr::on_btn_update_clicked()
{
    int r = ui->tableView->currentIndex().row();
    if(r<0){
        QMessageBox::information(nullptr,"信息","无选中图书");
    }else
    {
        auto id = m_model.item(r,0)->text();
        BookAU dlg;
        dlg.setType(id.toInt());
        dlg.exec();
        initPage();
    }
}


void BookMgr::on_btn_del_clicked()
{
    int r = ui->tableView->currentIndex().row();
    if(r<0){
        QMessageBox::information(nullptr,"信息","无选中图书");
    }else
    {
        auto id = m_model.item(r,0)->text();
        auto str = SqlMgr::getinstance()->DelBooks(id);
        QMessageBox::information(nullptr,"信息",str.isEmpty()?"删除图书成功":str);
        initPage();
    }
}


void BookMgr::on_btn_brw_clicked()
{
     int r = ui->tableView->currentIndex().row();
    if(r<0)
     {
         return;
    }
    auto id = m_model.item(r,0)->text();
    auto cnt = m_model.item(r,6)->text().toInt();
    if(cnt<=0){
        QMessageBox::information(nullptr,"信息","借阅失败没有库存");
        return;
    }
    BookGS dlg;
    dlg.setBookid(id);
    int ret = dlg.exec();
    QMessageBox::information(nullptr,"信息",ret?"借阅成功":"借阅失败");
}


void BookMgr::on_btn_rtn_clicked()
{

}


void BookMgr::on_le_srch_textChanged(const QString &arg1)
{
    QString strCond = QString("where name like '%%1%' or type1 like '%%1%'or type2 like '%%1%'or type3 like '%%1%'").arg(arg1);
    initPage(strCond);

}

