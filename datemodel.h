#ifndef DATEMODEL_H
#define DATEMODEL_H
#include <QList>
#include <QPixmap>
#include <QDir>
#include <QStringList>
#include <QDebug>
#include <QRegExpValidator>
#include <QRegExp>


class DateModel
{


public:
    QStringList listPath;
    int curNum;
    QPixmap * odinaryPixmap;
    DateModel();
    QPixmap * curPixmap;
    void  listInit(QString path,QString imagepath);
    int openPixmap(QString path);
    void showListPath();
    QString chargePathToDir(QString path);
    void clear();

    //DateModel();
};

#endif // DATEMODEL_H
