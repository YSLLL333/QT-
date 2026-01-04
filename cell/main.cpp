#include "mainwindow.h"

#include <QApplication>
#include "login.h"

#include "lib/sqlmgr.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SqlMgr::getinstance()->init();
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
