#ifndef BOOKMGR_H
#define BOOKMGR_H

#include <QStandardItemModel>
#include <QWidget>

namespace Ui {
class BookMgr;
}

class BookMgr : public QWidget
{
    Q_OBJECT

public:
    explicit BookMgr(QWidget *parent = nullptr);
    ~BookMgr();
    void initPage(QString strCondition="");
private slots:
    void on_btn_add_clicked();

    void on_btn_update_clicked();

    void on_btn_del_clicked();

    void on_btn_brw_clicked();



    void on_le_srch_textChanged(const QString &arg1);

private:
    Ui::BookMgr *ui;
    QStandardItemModel m_model;
};

#endif // BOOKMGR_H
