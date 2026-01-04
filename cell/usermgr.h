#ifndef USERMGR_H
#define USERMGR_H

#include <QWidget>
#include<QStandardItemModel>
namespace Ui {
class UserMgr;
}

class UserMgr : public QWidget
{
    Q_OBJECT

public:
    explicit UserMgr(QWidget *parent = nullptr);
    ~UserMgr();
    void initPage(QString strCondition = "");
private slots:
    void on_le_srch_textChanged(const QString &arg1);

    void on_btn_imprt_clicked();

    void on_btn_del_clicked();

private:
    Ui::UserMgr *ui;
    QStandardItemModel m_model;
};

#endif // USERMGR_H
