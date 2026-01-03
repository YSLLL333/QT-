#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_userPage(nullptr)
    ,m_bookPage(nullptr)
    ,m_recordPage(nullptr)
{
    ui->setupUi(this);
    initPage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initPage()
{
    m_userPage=new UserMgr(this);
    m_bookPage=new BookMgr(this);
    m_recordPage=new RecordMgr(this);
    ui->stackedWidget->addWidget(m_userPage);
    ui->stackedWidget->addWidget( m_bookPage);
    ui->stackedWidget->addWidget(m_recordPage);
    ui->stackedWidget->setCurrentWidget(0);
}
