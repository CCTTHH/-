#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "daylabel.h"
#include "ui_widget.h"
#include<QString>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:

    void on_pushButton_nm_clicked();

    void on_pushButton_ly_clicked();

    void on_year_spinBox_valueChanged(const QString &arg1);

    void on_month_spinBox_valueChanged(const QString &arg1);




    void on_pushButton_clicked();

private:

    Ui::Widget *ui;
    DayLabel *days[43];
    int w_year;
    int w_month;
    QDate crday;

    void inidate();
    QString isaholiday(QDate date);
    QString holidayplan(QDate date);
};

#endif // WIDGET_H
