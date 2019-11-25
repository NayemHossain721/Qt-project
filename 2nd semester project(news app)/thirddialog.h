#ifndef THIRDDIALOG_H
#define THIRDDIALOG_H

#include <QDialog>
#include <QFileDialog>
#include<QFile>
#include<QFileInfo>

namespace Ui {
class thirdDialog;
}

class thirdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit thirdDialog(QWidget *parent = nullptr);

    ~thirdDialog();

private slots:
    void on_submit2_clicked();

    void on_signout2_clicked();
    void on_newsfeed_clicked();


void on_Upload_clicked();

private:
    Ui::thirdDialog *ui;
};

#endif // THIRDDIALOG_H
