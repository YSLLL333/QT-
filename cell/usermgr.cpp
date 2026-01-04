#include "usermgr.h"
#include "ui_usermgr.h"

UserMgr::UserMgr(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserMgr)
{
    ui->setupUi(this);
    ui->tableView->setModel(&m_model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_model.setHorizontalHeaderLabels(QStringList{"用户id","年级","部门","用户名","密码","昵称","权限"});
#if 1
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
}
#endif

UserMgr::~UserMgr()
{
    delete ui;
}
