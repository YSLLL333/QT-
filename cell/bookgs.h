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

private:
    Ui::BookGS *ui;
};

#endif // BOOKGS_H
