#ifndef HELPUI_H
#define HELPUI_H

#include <QWidget>

namespace Ui {
class helpUI;
}

class helpUI : public QWidget
{
    Q_OBJECT

public:
    explicit helpUI(QWidget *parent = 0);
    ~helpUI();

private:
    Ui::helpUI *ui;
};

#endif // HELPUI_H
