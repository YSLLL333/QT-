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

void SqlMgr::AddUser(QVector<QStringList> v)
{
    m_db.transaction();
    QSqlQuery q(m_db);
    for(auto it:v){
        QString strSql = QString("insert into user VALUES(NULL,'%1','%2','%3','%4','%5','%6');").arg(it[0]).arg(it[1]).arg(it[2]).arg(it[3]).arg(it[4]).arg(it[5]);
        bool ret = q.exec(strSql);
        if(!ret){
            qDebug()<<q.lastError().text();
        }
    }

    m_db.commit();
}

void SqlMgr::DelUser(QString strid)
{
    QSqlQuery q(m_db);
    QString strSql = QString("delete from user where bookid =%1").arg(strid);
    bool ret = q.exec(strSql);
    if(!ret){
        qDebug()<<q.lastError().text();
    }
}

QVector<QStringList> SqlMgr::getBooks(QString strCondition)
{
    QSqlQuery q(m_db);
    QString strSql = QString("Select * from book %1").arg(strCondition);

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

QString SqlMgr::DelBooks(QString strid)
{
    QString strRet;
    QSqlQuery q(m_db);
    QString strSql = QString("delete from book where bookid =%1").arg(strid);
    bool ret = q.exec(strSql);
    if(!ret){
        qDebug()<<q.lastError().text();
        strRet ="删除失败，图书可能在被借阅中";
    }
    return strRet;
}



QVector<QStringList> SqlMgr::getRecord(QString strCondition)
{
    QSqlQuery q(m_db);
    QString strSql = QString("Select * from record %1").arg(strCondition);

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

void SqlMgr::ClrRecord()
{
    QSqlQuery q(m_db);
    QString strSql = QString("DELETE from book ;DELETE FROM sqlite_sequence WHERE name = 'book';");
    bool ret = q.exec(strSql);
    if(!ret){
        qDebug()<<q.lastError().text();
    }
}

