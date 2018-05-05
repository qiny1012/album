#include "helpui.h"
#include "ui_helpui.h"

helpUI::helpUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::helpUI)
{
    ui->setupUi(this);
}

helpUI::~helpUI()
{
    delete ui;
}
