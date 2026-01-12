#include "bookgs.h"
#include "ui_bookgs.h"

#include <lib/sqlmgr.h>

BookGS::BookGS(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BookGS)
{
    ui->setupUi(this);
}

BookGS::~BookGS()
{
    delete ui;
}

void BookGS::setType(bool isReturn)
{
    m_isReturn = isReturn;
}

void BookGS::setBookid(int id)
{
    m_bookid = id;
}

void BookGS::on_btn_get_clicked()
{
    do{
        auto strName = ui->le_user->text();
        auto strPass = ui->le_pswd->text();
        auto userid = 0;
         auto ret = SqlMgr::getinstance()->login(strName,strPass,userid);
        if(!ret){
            this->done(0);
            break;
        }
        if(m_isReturn){
             SqlMgr::getinstance()->RtnBooks(QString::number(userid),QString::number(m_bookid));
        }else{
             SqlMgr::getinstance()->BrwBooks(QString::number(userid),QString::number(m_bookid));
        }

        this->done(1);
    }while(false);


}


void BookGS::on_btn_cancel_clicked()
{
    this->done(0);
}

