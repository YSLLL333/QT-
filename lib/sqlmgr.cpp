#include "sqlmgr.h"
#include <QCoreApplication>
#include<QSqlQuery>
#include<QSqlError>
#include<QSqlRecord>
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
    QSqlQuery q(m_db);
    QString strSql = QString("Select * from user where username='%1' and password ='%2'").arg(strUser).arg(strPass);
    bool ret = q.exec(strSql);
    if(!ret){
        qDebug()<<q.lastError().text();
    }
    return ret;
}

QVector<QStringList> SqlMgr::getUser(QString strCondition)
{
    QSqlQuery q(m_db);
    QString strSql = QString("Select * from user %1").arg(strCondition);

    QVector<QStringList> vec;
    bool ret = q.exec(strSql);
    if(!ret){
        qDebug()<<q.lastError().text();
    }else
    {
        int iC = q.record().count();
        QStringList l;
        while(q.next()){
            l.clear();
            for(int i=0;i<iC;i++ ){
                l<<q.value(i).toString();
            }
            vec.push_back(l);
        }
    }
    return vec;
}

void SqlMgr::DelUser(QString strid)
{
    QSqlQuery q(m_db);
    QString strSql = QString("delete from user where userid =%1").arg(strid);
    bool ret = q.exec(strSql);
    if(!ret){
        qDebug()<<q.lastError().text();
    }
}

