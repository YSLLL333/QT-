#include "mainwindow.h"

#include <QApplication>
#include "login.h"

#include "lib/sqlmgr.h"

//剩余借阅sql 归还sql 登录sql
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SqlMgr::getinstance()->init();
    int bookid = 0;
    qDebug()<<"login ret"<<SqlMgr::getinstance()->login("xiaoz","123",bookid);
    auto v = SqlMgr::getinstance()->getUser("where username like '%x%' or nickname like '%t%' ");
    Login dlg;
    int ret=dlg.exec();

        if(1==ret)
        {
            MainWindow w;
            w.show();
              return a.exec();
        }
        if(0==ret)
        {
            exit(0);
            return 0;
        }
        return 0;
}
