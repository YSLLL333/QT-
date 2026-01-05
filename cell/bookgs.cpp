#include "bookgs.h"
#include "ui_bookgs.h"

BookGS::BookGS(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BookGS)
{
    ui->setupUi(this);
}

BookGS::~BookGS()
{
    delete ui;
}
