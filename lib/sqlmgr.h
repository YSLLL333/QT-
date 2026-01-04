#ifndef SQLMGR_H
#define SQLMGR_H

#include<QtDebug>
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

    void test();
};

#endif // SQLMGR_H
