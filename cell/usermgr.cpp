#include "usermgr.h"
#include "ui_usermgr.h"
#include "lib/sqlmgr.h"
#include<QMessageBox>
UserMgr::UserMgr(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserMgr)
{
    ui->setupUi(this);
    ui->tableView->setModel(&m_model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_model.setHorizontalHeaderLabels(QStringList{"用户id","用户名","密码","昵称","权限","部门","年级"});
#if 0
    for(int i =0;i<10;i++){    QList<QStandardItem*> items;
        items.append(new QStandardItem("1"));
        items.append(new QStandardItem("1年1班"));
        items.append(new QStandardItem("软件工程"));
        items.append(new QStandardItem("zhangsan"));
        items.append(new QStandardItem("123"));
        items.append(new QStandardItem("小张"));
        items.append(new QStandardItem("学生"));
        m_model.appendRow(items);
    }
    #endif
}


UserMgr::~UserMgr()
{
    delete ui;
}

void UserMgr::initPage(QString strCondition)
{
    //查询数据库并显示
    auto l=SqlMgr::getinstance()->getUser(strCondition);
    m_model.clear();
    m_model.setHorizontalHeaderLabels(QStringList{"用户id","用户名","密码","昵称","权限","部门","年级"});
    for(int i =0;i<l.size();i++){    QList<QStandardItem*> items;

        for(int j=0;j<l[i].size();j++){
            items.append(new QStandardItem(l[i][j]));
        }
        m_model.appendRow(items);
    }
}


void UserMgr::on_le_srch_textChanged(const QString &arg1)
{
    QString strCond = QString("where username like '%%1%' or nickname like '%%1%'").arg(arg1);
    initPage(strCond);
}


void UserMgr::on_btn_imprt_clicked()
{
    //导入用户
}


void UserMgr::on_btn_del_clicked()
{
    //删除用户
   int r = ui->tableView->currentIndex().row();
    if(r<0){
       QMessageBox::information(nullptr,"信息","无选中用户");
    }else
    {
        auto id = m_model.item(r,0)->text();
        SqlMgr::getinstance()->DelUser(id);
        initPage();
    }
}

