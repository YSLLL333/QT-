#include "login.h"
#include "ui_login.h"
#include "lib/sqlmgr.h"

#include <QMessageBox>
Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_btn_login_clicked()
{    int bookid = 0;
    auto ret = SqlMgr::getinstance()->login(ui->lineEdit->text(),ui->lineEdit_2->text(),bookid);
    if(ret){
        setResult(1);
         hide();
    }else{
        QMessageBox::information(nullptr,"信息","用户名或密码错误");
    }

}


void Login::on_btn_exit_clicked()
{
    setResult(0);
    hide();
}

