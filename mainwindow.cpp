#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QScrollArea>
#include <QFileDialog>
#include <QMessageBox>
#include <helpui.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QScrollArea * scrollArea = new QScrollArea(this);
    scrollArea->setAlignment(Qt::AlignCenter);
    scrollArea->setFrameShape(QFrame::NoFrame);
    scrollArea->setWidget(ui->label);
    scrollArea->setGeometry(0,70,800,600);
    ui->label->setAlignment(Qt::AlignCenter);
    /*
    ui->Prev->setGeometry(133,625,75,30);
    ui->Next->setGeometry(283,625,75,30);
    ui->Enlarge->setGeometry(433,625,75,30);
    ui->Narrow->setGeometry(583,625,75,30);
    ui->label->setGeometry(0,0,790,590);
    */

    //connect(ui->actionOpen,SIGNAL(triggered(bool)),this,SLOT(on_actionOpen_triggered()));
    //connect(ui->actionClose,SIGNAL(triggered(bool)),this,SLOT(on_actionClose_triggered()));
    // connect(ui->actionShanchu,SIGNAL(triggered(bool)),this,SLOT(on_actionShanchu_triggered()));
    //connect(ui->actionQuit,SIGNAL(triggered(bool)),this,SLOT(close()));
    connect(ui->actionShangyizhang,SIGNAL(triggered(bool)),this,SLOT(on_Prev_clicked()));
    connect(ui->actionXiayizhang,SIGNAL(triggered(bool)),this,SLOT(on_Next_clicked()));
    connect(ui->actionFangda,SIGNAL(triggered(bool)),this,SLOT(on_Enlarge_clicked()));
    connect(ui->actionSuoxia,SIGNAL(triggered(bool)),this,SLOT(on_Narrow_clicked()));


    connect(ui->toolbarOpen,SIGNAL(triggered(bool)),this,SLOT(on_actionOpen_triggered()));
    connect(ui->toolbarClose,SIGNAL(triggered(bool)),this,SLOT(on_actionClose_triggered()));
    connect(ui->toolbarDelete,SIGNAL(triggered(bool)),this,SLOT(on_actionShanchu_triggered()));
    connect(ui->toolbarQuit,SIGNAL(triggered(bool)),this,SLOT(close()));
    connect(ui->toolbarPre,SIGNAL(triggered(bool)),this,SLOT(on_Prev_clicked()));
    connect(ui->toolbarNext,SIGNAL(triggered(bool)),this,SLOT(on_Next_clicked()));
    connect(ui->toolbarEnage,SIGNAL(triggered(bool)),this,SLOT(on_Enlarge_clicked()));
    connect(ui->toolbarSmall,SIGNAL(triggered(bool)),this,SLOT(on_Narrow_clicked()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName =  QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     "/home",
                                                     tr("Images (*.png *.xpm *.jpg *.jpeg *.bmp)"));
    this->date.openPixmap(fileName);
    ui->label->setPixmap(*(this->date.curPixmap));
    ui->label->setGeometry(0,0,this->date.curPixmap->width(),this->date.curPixmap->height());
    this->date.showListPath();
    pixmap = *(date.curPixmap);
    owidth = pixmap.width();
}

void MainWindow::on_Prev_clicked()
{
    if(date.curPixmap == NULL)
    {
        QMessageBox::warning(this,tr("warning"),tr("没有打开文件!!"));
        return ;
    }
    this->date.curNum--;
    if(this->date.curNum == -1)
    {
         this->date.curNum =  this->date.listPath.size() - 1;
    }
    pixmap.load(this->date.listPath.at(this->date.curNum));
    ui->label->setPixmap(pixmap);
    ui->label->setGeometry(0,0,pixmap.width(),pixmap.height());
    owidth = pixmap.width();
}

void MainWindow::on_Next_clicked()
{
    if(date.curPixmap == NULL)
    {
        QMessageBox::warning(this,tr("warning"),tr("not open file!!"),QMessageBox::Ok);
        return ;
    }
    this->date.curNum++;
    if(this->date.curNum == this->date.listPath.size())
    {
         this->date.curNum =  0;
    }
    pixmap.load(this->date.listPath.at(this->date.curNum));
    this->date.curPixmap = &pixmap;
    ui->label->setPixmap(pixmap);
    ui->label->setGeometry(0,0,pixmap.width(),pixmap.height());
    owidth = pixmap.width();
}

void MainWindow::on_Enlarge_clicked()
{
    if(date.curPixmap == NULL)
    {
        QMessageBox::warning(this,tr("warning"),tr("没有打开文件!!"));
        return ;
    }
    //this->pixmap = * (date.curPixmap);
    int width =  owidth * 0.2 + pixmap.width();
    if(width >  owidth * 5)
    {
        return ;
    }
    else if(width == owidth)
    {
        pixmap.load(this->date.listPath.at(this->date.curNum));
    }
    else
    {
        pixmap = pixmap.scaledToWidth(width);
    }
    ui->label->setPixmap(pixmap);
    ui->label->setGeometry(0,0,pixmap.width(),pixmap.height());
}

void MainWindow::on_Narrow_clicked()
{
    if(date.curPixmap == NULL)
    {
        QMessageBox::warning(this,tr("warning"),tr("没有打开文件!!"));
        return ;
    }
    int width = -owidth * 0.2 +  pixmap.width();
    if(width < owidth * 0.2)
    {
        return ;
    }else if(width == owidth)
    {
        pixmap.load(this->date.listPath.at(this->date.curNum));
    }
    else
    {
        pixmap = pixmap.scaledToWidth(width);
    }
    ui->label->setPixmap(pixmap);
    ui->label->setGeometry(0,0,pixmap.width(),pixmap.height());
}

void MainWindow::on_actionClose_triggered()
{
    if(date.curPixmap == NULL)
    {
        QMessageBox::warning(this,tr("warning"),tr("没有打开文件!!"));
        return ;
    }
    date.clear();
    //QPixmap backPix ;
    //backPix.load(":/op/11.png");
    //ui->label->setPixmap(backPix);
    ui->label->clear();
}

void MainWindow::on_actionShanchu_triggered()
{
    if(date.curPixmap == NULL)
    {
        QMessageBox::warning(this,tr("warning"),tr("没有打开文件!!"));
        return ;
    }

    QString path = date.listPath.at(date.curNum);
    QFile file(path);
    //file.destroyed();
    file.remove();
    this->on_actionClose_triggered();
}

void MainWindow::on_actionBangzhu_triggered()
{
    helpUI * helpui = new helpUI();
    helpui->show();
}

void MainWindow::on_actionGuanyu_triggered()
{
    QMessageBox::information(this,tr("版权信息"),tr("图相查看软件采用QT和c++完成.代码全部是开源的.图片是没有版权的.如果使用自己需要替换.如果有问题或者bug提交联系邮箱1040564948@qq.com"));
}
