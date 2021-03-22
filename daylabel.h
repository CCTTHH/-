#ifndef DAYLABEL_H
#define DAYLABEL_H




#include <QWidget>
#include <QLabel>
#include<Qdate>


QT_BEGIN_NAMESPACE
class QPushButton;
class QComboBox;
class QGroupBox;
class QLineEdit;
class QDate;
class QGridLayout;
class QHBoxLayout;
class QVBoxLayout;

class Event;
class DataBase;
QT_END_NAMESPACE

typedef enum {
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Week
} E_WEEK;

typedef enum {
    PREV_MONTH_DAY,     // 上月剩余天数
    NEXT_MONTH_DAY,     // 下个月的天数
    CURR_MONTH_DAY,     // 当月天数
    WEEKEND_DAY,        // 周末
    CURRENT_DAY,        // 当天
} E_DAY;

///////////////////////////////////////////////
/// \brief The DayLabel class
/// 自定义的日子显示控件
///////////////////////////////////////////////
class DayLabel : public QLabel {
    Q_OBJECT

public:
    explicit DayLabel(QWidget *parent = 0);

    bool bSelect;

    void setSelected(bool value);
    void setColor(const int &type);
    void setDay(int nDay, QString strLunar);

    int m_nDay;
    void setPlan(QString plan);
signals:
    void signalClicked(int ntype, int day);
    void signalPlan(const QString &content);
private:

    QString m_strListPlan;
protected:
    void enterEvent(QEvent *e);
    void leaveEvent(QEvent *e);
    void mousePressEvent(QMouseEvent *e);

};

#endif // DAYLABEL_H
