#include "bookau.h"
#include "ui_bookau.h"
#include "lib/sqlmgr.h"

BookAU::BookAU(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BookAU)
{
    ui->setupUi(this);
}

BookAU::~BookAU()
{
    delete ui;
}

void BookAU::setType(int id)
{
    m_id = id;
    //执行sql语句获取图书信息并显示到对应的控件上
}

void BookAU::on_btn_ok_clicked()
{
    QStringList l;
    l<<QString::number(m_id);
    l<<ui->le_name->text();
    l<<ui->le_press->text();
    l<<ui->cb1->currentText();
    l<<ui->cb2->currentText();
    l<<ui->cb3->currentText();
    l<<ui->le_cnt->text();
    l<<"";
    if(-1 !=m_id)
    {
        //update
        SqlMgr::getinstance()->UpdateBooks(l);
    }
    else{
        //add
        QVector<QStringList> vec;
        vec.push_back(l);
        SqlMgr::getinstance()->AddBooks(vec);
    }
    this->hide();
}


void BookAU::on_btn_cancel_clicked()
{
    this->hide();
}

