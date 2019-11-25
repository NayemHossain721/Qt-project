#ifndef PICDIALOG_H
#define PICDIALOG_H

#include <QDialog>

namespace Ui {
class picDialog;
}

class picDialog : public QDialog
{
    Q_OBJECT

public:
    explicit picDialog(QWidget *parent = nullptr);
    ~picDialog();

private:
    Ui::picDialog *ui;
};

#endif // PICDIALOG_H
