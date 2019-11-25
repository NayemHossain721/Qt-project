#include "picdialog.h"
#include "ui_picdialog.h"

picDialog::picDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::picDialog)
{
    ui->setupUi(this);
}

picDialog::~picDialog()
{
    delete ui;
}
