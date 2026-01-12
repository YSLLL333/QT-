#ifndef RECORDMGR_H
#define RECORDMGR_H

#include <QStandardItemModel>
#include <QWidget>

namespace Ui {
class RecordMgr;
}

class RecordMgr : public QWidget
{
    Q_OBJECT

public:
    explicit RecordMgr(QWidget *parent = nullptr);
    ~RecordMgr();
    void initPage(QString strCondition="");
private slots:
    void on_le_srch_textChanged(const QString &arg1);

    void on_btn_clr_clicked();

    void on_pushButton_clicked();

private:
    Ui::RecordMgr *ui;
    QStandardItemModel m_model;
};

#endif // RECORDMGR_H
