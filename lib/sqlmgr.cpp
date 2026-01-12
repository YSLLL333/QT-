#include "sqlmgr.h"
#include <QCoreApplication>
#include<QSqlQuery>
#include<QSqlError>
#include<QSqlRecord>
#include <QDateTime>
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

bool SqlMgr::login(QString strUser, QString strPass,int &Userid)
{
    QSqlQuery q(m_db);
    QString strSql = QString("Select * from user where username='%1' and password ='%2'").arg(strUser).arg(strPass);
    bool ret = q.exec(strSql);
    if(!ret){
        qDebug()<<q.lastError().text();
    }else{
        q.next();
        Userid = q.value(0).toInt();
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
    QString strSql = QString("delete from user where userid =%1").arg(strid);
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

void SqlMgr::AddBooks(QVector<QStringList> vec)
{
    if(0 == vec.size()){
        return;
    }
    auto ldata = vec[0];
    QSqlQuery q(m_db);
    QString strSql = QString("INSERT INTO book "
                             "values(null,'%1','%2','%3','%4','%5',%6,'')")
                         .arg(ldata[1]).arg(ldata[2]).arg(ldata[3]).arg(ldata[4]).arg(ldata[5]).arg(ldata[6]);
    bool ret = q.exec(strSql);

    if(!ret){
        qDebug()<<q.lastError().text();
    }
}

void SqlMgr::UpdateBooks(QStringList ldata)
{
    QSqlQuery q(m_db);
    QString strSql = QString("UPDATE book"
                             " set name = '%1',press='%2',type1 = '%3',type2 = '%4',type3 = '%5',cnt = '%6'"" where bookid =%7")
                         .arg(ldata[1]).arg(ldata[2]).arg(ldata[3]).arg(ldata[4]).arg(ldata[5]).arg(ldata[6]).arg(ldata[0]);
    bool ret = q.exec(strSql);

    if(!ret){
        qDebug()<<q.lastError().text();
    }
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

QString SqlMgr::RtnBooks(QString strUserId, QString strBookid)
{

}

QString SqlMgr::BrwBooks(QString strUserId, QString strBookid)
{
    //实现图书借阅
    QSqlQuery q(m_db);
    QString strSql = QString("update book set cnt = cnt-1 where bookid =%1;"
                             "insert into record VALUES(null,%2,%3,%4,%5)")
                         .arg(strBookid).arg(strUserId).arg(strBookid).arg(QDateTime::currentSecsSinceEpoch()).arg(QDateTime::currentSecsSinceEpoch()+3600*24*10);
    bool ret = q.exec(strSql);
    if(!ret){
        qDebug()<<q.lastError().text();
    }
    return QString("");
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

