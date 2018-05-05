#include "datemodel.h"

DateModel::DateModel()
{
    this->curNum = 0;
}

void DateModel::listInit(QString path,QString imagepath)
{
    //qDebug() << path <<endl;
    QDir * dir = new QDir(path);
    //listPath = dir->nameFilters();
    QStringList nameFilters;
    nameFilters << "*.jpg" << "*.png" << "*.bmp" << "*.jpeg" \
                << "*.JPG" << "*.PNG" << "*.BMP" << "*.JPEG" ;
    QStringList list = dir->entryList(nameFilters);
    for(int i = 0; i <list.size();i++)
    {
       QString end = path;
       end.append(list.at(i));
       listPath << end ;
       if(end == imagepath)
       {
           curNum = i;
       }
    }
    qDebug() << "curNum:" << curNum << endl;
    //qDebug() <<listPath.size();
    delete dir;
}

int DateModel::openPixmap(QString path)
{
    curPixmap = new QPixmap(path);
    if(NULL == curPixmap)
    {
        return -1;
    }
    else
    {
        QString dir = chargePathToDir(path);
        this->listInit(dir,path);
        return 1;
    }
    //odinaryPixmap = new QPixmap(path);
}

void DateModel::showListPath()
{
    qDebug() << "*********************showList***********************" << endl;
    for(int i = 0; i<listPath.length();i++)
    {
        qDebug()<< listPath.at(i) <<endl;
    }
}

QString DateModel::chargePathToDir(QString path)
{
    //QRegExpValidator rev = new QRegExpValidator(QRegExp(tr("[0-9]+")),this);
    QStringList list = path.split("/");
    QString endPath;
    for(int i = 0;i < list.size()-1;i++)
    {
        //qDebug() << list.at(i) <<endl;
        //qDebug() << list.at(0) <<endl;
        endPath = endPath.append(list.at(i));
        endPath = endPath.append("/");
    }
    return endPath;
}

void DateModel::clear()
{
    //delete curPixmap;
    curPixmap = NULL;
    curNum = 0;
    listPath.clear();
}




