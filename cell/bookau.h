#ifndef BOOKAU_H
#define BOOKAU_H

#include <QDialog>

namespace Ui {
class BookAU;
}

class BookAU : public QDialog
{
    Q_OBJECT

public:
    explicit BookAU(QWidget *parent = nullptr);
    ~BookAU();

    void setType(int id);
private slots:
    void on_btn_ok_clicked();

    void on_btn_cancel_clicked();

private:
    Ui::BookAU *ui;
    int m_id= -1;
};

#endif // BOOKAU_H
