#ifndef LONGINFORM_H
#define LONGINFORM_H

#include <QWidget>
#include "mainwindow.h"
namespace Ui {
class LonginForm;
}

class LonginForm : public QWidget
{
    Q_OBJECT

public:
    explicit LonginForm(QWidget *parent = 0);

    ~LonginForm();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::LonginForm *ui;
};

#endif // LONGINFORM_H
