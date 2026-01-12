#ifndef BOOKGS_H
#define BOOKGS_H

#include <QDialog>

namespace Ui {
class BookGS;
}

class BookGS : public QDialog
{
    Q_OBJECT

public:
    explicit BookGS(QWidget *parent = nullptr);
    ~BookGS();
    void setBookid(int id);
private slots:
    void on_btn_get_clicked();

    void on_btn_cancel_clicked();

private:
    Ui::BookGS *ui;
    int m_bookid;
};

#endif // BOOKGS_H
