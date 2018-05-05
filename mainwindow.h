#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "datemodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_Prev_clicked();

    void on_Next_clicked();

    void on_Enlarge_clicked();

    void on_Narrow_clicked();

    void on_actionClose_triggered();

    void on_actionShanchu_triggered();

    void on_actionBangzhu_triggered();

    void on_actionGuanyu_triggered();

private:
    Ui::MainWindow *ui;
    DateModel date;
    QPixmap pixmap;
    int owidth;
};

#endif // MAINWINDOW_H
