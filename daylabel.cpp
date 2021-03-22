#include <QInputDialog>
#include <QPainter>
#include <QStyleOption>
#include <QDateTime>
#include <QPushButton>
#include <QLineEdit>
#include <QGroupBox>
#include <QLabel>
#include <QDate>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QDebug>
#include <QFont>
#include"daylabel.h"
#include <QMouseEvent>
#include <QEvent>
#include <QPixmap>
#include "widget.h"

DayLabel::DayLabel(QWidget *parent):
    QLabel(parent)
{
    bSelect = false;
    m_nDay = 0;
    m_strListPlan.clear();


}


void DayLabel::setSelected(bool value)
{
    bSelect = value;
    this->setStyleSheet("background: #ffffff; border: 1px solid red; border-radius: 2px");
}

void DayLabel::setColor(const int &type)
{
    // 设置控件属性类型
    this->setProperty("type", type);
    this->setSelected(CURRENT_DAY == type);

    // 其他月
    if ((PREV_MONTH_DAY == type) || (NEXT_MONTH_DAY == type)) {
        this->setStyleSheet("background: #7f7f7f; border-top: 1px solid #c3c3c3; border-left: 1px solid #c3c3c3; color: #999999;");

    }
    // 当前月
    else if (CURR_MONTH_DAY == type) {
        this->setStyleSheet("background: #ffffff; border-top: 1px solid #c3c3c3; border-left: 1px solid #c3c3c3; color: #000000;");
    }
    // 周末
    else if (WEEKEND_DAY == type) {

        this->setStyleSheet("background: #ffffff; border-top: 1px solid #c3c3c3; border-left: 1px solid #c3c3c3; color: #ff0000;");
    }
}

/**
 * @brief DayLabel::showDay
 * @param nDay
 * @param strLunar
 * @param type
 */
void DayLabel::setDay(int nDay, QString strLunar)
{
    QString strText = QString::number(nDay);
    this->m_nDay = nDay;

    if ("" != strLunar) {
        strText.append("\n");
        strText.append(strLunar);
    }

    this->setText(strText);
}

/**
 * @brief DayLabel::setPlan 设置计划和日程
 * @param plan
 */
void DayLabel::setPlan(QString plan)
{
    if (!plan.isEmpty()) {
        m_strListPlan = plan;

    }
    else {
        m_strListPlan.clear();
    }


}

void DayLabel::enterEvent(QEvent *e)
{
    int nProperty = this->property("type").toInt();
    if (PREV_MONTH_DAY == nProperty || NEXT_MONTH_DAY == nProperty) return;

    this->setStyleSheet("background: #c8b9a6; border-top: 1px solid #c3c3c3; border-left: 1px solid #c3c3c3;");




    QLabel::enterEvent(e);
}

void DayLabel::leaveEvent(QEvent *e)
{
    int nProperty = this->property("type").toInt();
    if (PREV_MONTH_DAY == nProperty || NEXT_MONTH_DAY == nProperty) return;

    if (bSelect) {
        this->setStyleSheet("background: #ffffff; border: 1px solid red;");
    }
    else {
        this->setStyleSheet("background: #ffffff; border-top: 1px solid #c3c3c3; border-left: 1px solid #c3c3c3;");
    }

    QLabel::leaveEvent(e);
}

void DayLabel::mousePressEvent(QMouseEvent *e)
{
    //qDebug() << this->text() << this->property("type").toInt();
    Q_EMIT signalClicked(this->property("type").toInt(), m_nDay);
    if (!m_strListPlan.isEmpty()) {
        Q_EMIT signalPlan(m_strListPlan);
    }
    else {
         Q_EMIT signalPlan(tr(""));
    }
    QLabel *label1 = new QLabel();
    //创建一个标签，此处输出具体日期
    QFont ft;
    ft.setPointSize(12);
    label1->setWindowTitle("事件");


               label1->resize(800,400);

               label1->setText(m_strListPlan);

               label1->setStyleSheet("background: #ffffff;");



               label1->setFont(ft);

               label1->setAlignment(Qt::AlignHCenter);

               label1->show();
    QLabel::mousePressEvent(e);
}

