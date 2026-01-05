#ifndef SQLMGR_H
#define SQLMGR_H

#include<QtDebug>
#include<QSqlDatabase>
class SqlMgr
{
public:
    SqlMgr();
    ~SqlMgr();

    static SqlMgr* instance;
    static SqlMgr* getinstance(){
        if(nullptr == instance){
            instance = new SqlMgr();
        }
        return instance;
    }

    void init();
    //登录
    bool login(QString strUser , QString strPass);

    //获取所有用户
    QVector<QStringList> getUser(QString strCondition="");

    //添加用户
    void AddUser(QVector<QStringList>);

    //删除
    void DelUser(QString strid);

    //获取所有图书
    QVector<QStringList> getBooks(QString strCondition="");

    //增加图书
    void AddBooks(QVector<QStringList>);

    //修改图书
    void UpdateBooks(QStringList);

    //删除图书
    QString DelBooks(QString strid);

    //图书归还
    QString RtnBooks(QString strUserId,QString strBookid);

    //图书借阅
    QString BrwBooks(QString strUserId,QString strBookid);

    //获取借阅记录
    QVector<QStringList> getRecord(QString strCondition="");

    //清空借阅记录
    void ClrRecord();

private:
    QSqlDatabase m_db;
};

#endif // SQLMGR_H
