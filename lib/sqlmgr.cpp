#include "sqlmgr.h"
#include <QCoreApplication>
SqlMgr* SqlMgr::instance = nullptr;

SqlMgr::SqlMgr() {}

SqlMgr::~SqlMgr()
{

}

void SqlMgr::init()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    qDebug()<<QSqlDatabase::drivers();
    m_db.setDatabaseName("C:/Users/LH/Desktop/QT/bin/bd/book.db");
    qDebug()<<m_db.open();
}

bool SqlMgr::login(QString strUser, QString strPass)
{


}

