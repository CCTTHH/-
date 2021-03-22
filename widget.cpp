#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    days[0] = 0;
    days[1] = ui->label_1;
    days[2] = ui->label_2;
    days[3] = ui->label_3;
    days[4] = ui->label_4;
    days[5] = ui->label_5;
    days[6] = ui->label_6;
    days[7] = ui->label_7;
    days[8] = ui->label_8;
    days[9] = ui->label_9;
    days[10] = ui->label_10;
    days[11] = ui->label_11;
    days[12] = ui->label_12;
    days[13] = ui->label_13;
    days[14] = ui->label_14;
    days[15] = ui->label_15;
    days[16] = ui->label_16;
    days[17] = ui->label_17;
    days[18] = ui->label_18;
    days[19] = ui->label_19;
    days[20] = ui->label_20;
    days[21] = ui->label_21;
    days[22] = ui->label_22;
    days[23] = ui->label_23;
    days[24] = ui->label_24;
    days[25] = ui->label_25;
    days[26] = ui->label_26;
    days[27] = ui->label_27;
    days[28] = ui->label_28;
    days[29] = ui->label_29;
    days[30] = ui->label_30;
    days[31] = ui->label_31;
    days[32] = ui->label_32;
    days[33] = ui->label_33;
    days[34] = ui->label_34;
    days[35] = ui->label_35;
    days[36] = ui->label_36;
    days[37] = ui->label_37;
    days[38] = ui->label_38;
    days[39] = ui->label_39;
    days[40] = ui->label_40;
    days[41] = ui->label_41;
    days[42] = ui->label_42;


    for(int i = 1;i<=42;i++)
    {
        days[i]->setText("gg");


    }
    crday = QDate::currentDate();
    w_year = crday.year();
    w_month  = crday.month();

    ui->year_spinBox->setValue(crday.year());
    ui->month_spinBox->setValue(crday.month());
    inidate();



}

Widget::~Widget()
{
    delete ui;
}
void Widget::inidate(void)
{

    QDate thefirstday(w_year,w_month,1);

    int dayofweek = thefirstday.dayOfWeek();
    int daysinmonth = thefirstday.daysInMonth();
    int daysinlastmonth;
    int lastyesyear;
    int lastmonth;

    if(w_month == 1)
    {

        lastmonth = 12;
        lastyesyear = w_year-1;
        QDate temp(lastyesyear,lastmonth,1);
        daysinlastmonth = temp.daysInMonth();


    }
    else
    {

        lastmonth  = w_month-1;
        lastyesyear = w_year;
        QDate temp(lastyesyear,lastmonth,1);
        daysinlastmonth = temp.daysInMonth();

    }


    for(int i=1;i<=42;i++)
    {

        days[i]->setPlan("");

    }


        for(int i = 1;i<=dayofweek;i++)
        {
            QDate date_temp(lastyesyear,lastmonth,daysinlastmonth-dayofweek+i);
            QString hol = isaholiday(date_temp);
           if(hol!="")
            {
               QString holp = holidayplan(date_temp);
            days[i]->setPlan(holp);
           }

            days[i]->setDay(daysinlastmonth-dayofweek+i,hol);
            days[i]->setColor(PREV_MONTH_DAY);

        }
        for(int i = dayofweek+1,y=1;y<=daysinmonth;i++,y++)
        {
            QDate date_temp(w_year,w_month,y);
            QString hol = isaholiday(date_temp);

            if(hol!="")
             {
                QString holp = holidayplan(date_temp);
             days[i]->setPlan(holp);
            }
            days[i]->setDay(y,hol);
            if(w_year == crday.year()&&w_month==crday.month()&&y==crday.day())
            {
                days[i]->setColor(CURRENT_DAY);

            }

            else
            {
                days[i]->setColor(CURR_MONTH_DAY);

            }





        }
        for(int i = 1, y=dayofweek+daysinmonth+1;i<=42- dayofweek-daysinmonth;i++,y++)
        {
            if(w_month==12)
            {

                QDate date_temp(w_year+1,1,i);
                QString hol = isaholiday(date_temp);
                if(hol!="")
                 {
                    QString holp = holidayplan(date_temp);
                 days[y]->setPlan(holp);
                }
                days[y]->setDay(i,hol);
                days[y]->setColor(NEXT_MONTH_DAY);
            }
            else
            {
                QDate date_temp(w_year,w_month+1,i);
                QString hol = isaholiday(date_temp);
                if(hol!="")
                 {
                    QString holp = holidayplan(date_temp);
                 days[y]->setPlan(holp);
                }
                days[y]->setDay(i,hol);
                days[y]->setColor(NEXT_MONTH_DAY);
            }
        }








}
 QString Widget::isaholiday(QDate date)
 {

     int temp = (date.month() << 8) | date.day();

        QString strHoliday = "";

        switch (temp)
        {

        case 0x0101: strHoliday = tr("元旦");  break;

        case 0x020B: strHoliday = tr("建国纪念日"); break;

        case 0x041D: strHoliday = tr("昭和之日"); break;

        case 0x0503: strHoliday = tr("宪法纪念日"); break;

        case 0x0504: strHoliday = tr("绿之日"); break;

        case 0x0505: strHoliday = tr("儿童节"); break;

        case 0x080B: strHoliday = tr("山之日"); break;

        case 0x0910: strHoliday = tr("敬老日"); break;

        case 0x0B03: strHoliday = tr("文化日"); break;

        case 0x0B23: strHoliday = tr("劳动感谢日"); break;

        case 0x0C17: strHoliday = tr("天皇诞辰"); break;

        default: break;
        }
        if(date.month()==1&&date.dayOfWeek()==1&&date.day()/7==1)// adult day
        {
              strHoliday = tr("成人之日");

        }
        if(date.month()==10&&date.dayOfWeek()==1&&date.day()/7==1)//sports day
        {
              strHoliday = tr("体育之日");
        }
        if(date.month()==7&&date.dayOfWeek()==1&&date.day()/7==2)//sea day
        {
              strHoliday = tr("海之日");
        }
        return strHoliday;

 }

 QString Widget::holidayplan(QDate date)
 {
     int temp = (date.month() << 8) | date.day();

        QString strHoliday = "";

        switch (temp)
        {

        case 0x0101: strHoliday = tr("元旦\n 1.1——元旦（元旦）除夕晚上全家团聚吃过年面，\n半夜听“除夕钟声”守岁。元旦早上吃年糕汤.\n日本的新年是日本人一年中最重要的节日之一。");

         break;

        case 0x020B: strHoliday = tr("建国纪念日\n国庆节（建国纪念日）根据日本神话，神武天皇于公元前660年2\n月11日建国，故宪法上将这一天定为建国纪念日。");
            break;

        case 0x041D: strHoliday = tr("昭和之日\n昭和の日昭和天皇裕仁的生日");
            break;

        case 0x0503: strHoliday = tr("宪法纪念日\n宪法纪念日（宪法纪念日）1947年5月3日，\n日本现行宪法开始实施");
            break;

        case 0x0504: strHoliday = tr("绿之日\n绿の日此节在1988年—2006年为国民休息日\n（国民の休日）。");
            break;

        case 0x0505: strHoliday = tr("儿童节\n儿童节（こどもの日）端午节也在这一天。\n是庆祝小孩成长，祈求幸福之日。");
            break;

        case 0x080B: strHoliday = tr("山之日\n8.11———山节（山の日）\n这既是一个夏季登山的好日子，\n同时靠近盂兰盆节，对企业活动影响较小。");
            break;

        case 0x0910: strHoliday = tr("敬老日\n敬老节（敬老の日）以尊敬老人、感谢老人为宗旨");
            break;

        case 0x0B03: strHoliday = tr("文化日\n文化节（文化の日）用以提倡热爱自由平等，\n促进文化事业的社会原则。");

             break;

        case 0x0B23: strHoliday = tr("劳动感谢日\n劳动感恩节（勤労感谢の日）\n此时正值收获的季节，为了表示对收获的谢意，\n而制定了以感谢劳动为宗旨的节日。");


            break;

        case 0x0C17: strHoliday = tr("天皇诞辰\n天皇生日（天皇诞生日）\n明仁天皇于1933年12月23日出生。");
            break;

        default: break;
        }
        if(date.month()==1&&date.dayOfWeek()==1&&date.day()/7==1)// adult day
        {
              strHoliday = tr("成人之日\n一月第二个星期一———\n成人节（成人の日）\n是庆祝年满20岁的青年男女成人自立的节日");

        }
        if(date.month()==10&&date.dayOfWeek()==1&&date.day()/7==1)//sports day
        {
              strHoliday = tr("体育之日\n十月第二个星期一——---\n体育节（体育の日）\n纪念1964年在东京举行的奥林匹克运动会开幕式的日子。");
        }
        if(date.month()==7&&date.dayOfWeek()==1&&date.day()/7==2)//sea day
        {
              strHoliday = tr("海之日\n七月第三个星期一———\n海节（海の日）日本四面环海，\n为了感谢得自海洋的恩典，\n并祈祷能成为国运昌隆的海洋国家而制订。");
        }
        return strHoliday;

 }

void Widget::on_pushButton_nm_clicked()
{
    w_month++;
    if(ui->month_spinBox->value()==12)
    {
        ui->month_spinBox->setValue(1);
        ui->year_spinBox->stepUp();
    }
    else
        ui->month_spinBox->stepUp();
    inidate();
    if(w_month==12)
    {
        w_year++;
        w_month = 1;
    }
}

void Widget::on_pushButton_ly_clicked()
{
    w_month--;
    if(ui->month_spinBox->value()==1)
    {
        ui->month_spinBox->setValue(12);
        ui->year_spinBox->stepDown();
    }
    else
        ui->month_spinBox->stepDown();
    inidate();
    if(w_month==1)
    {
        w_year--;
        w_month = 12;
    }
}
void Widget::on_year_spinBox_valueChanged(const QString &arg1)
{
    w_year = arg1.toInt();
    inidate();
}

void Widget::on_month_spinBox_valueChanged(const QString &arg1)
{
    w_month = arg1.toInt();
    inidate();


}






void Widget::on_pushButton_clicked()
{
    QString search;
    int year=0;
    year=ui->spinBox->value();
    search =  ui->lineEdit->text();
    if(search=="元旦")
    {
        QDate date(year,1,1);
        ui->label->setText(date.toString(Qt::SystemLocaleShortDate));

    }

    if(search=="建国纪念日")
    {
        QDate date(year,2,11);
        ui->label->setText(date.toString(Qt::SystemLocaleShortDate));

    }

    if(search=="昭和之日")
    {
        QDate date(year,4,29);
        ui->label->setText(date.toString(Qt::SystemLocaleShortDate));

    }

    if(search=="宪法纪念日")
    {
        QDate date(year,5,3);
        ui->label->setText(date.toString(Qt::SystemLocaleShortDate));

    }

    if(search=="绿之日")
    {
        QDate date(year,5,4);
        ui->label->setText(date.toString(Qt::SystemLocaleShortDate));

    }

    if(search=="儿童节")
    {
        QDate date(year,5,5);
        ui->label->setText(date.toString(Qt::SystemLocaleShortDate));

    }

    if(search=="山之日")
    {
        QDate date(year,8,11);
        ui->label->setText(date.toString(Qt::SystemLocaleShortDate));

    }

    if(search=="敬老日")
    {
        QDate date(year,9,16);
        ui->label->setText(date.toString(Qt::SystemLocaleShortDate));

    }

    if(search=="文化日")
    {
        QDate date(year,11,3);
        ui->label->setText(date.toString(Qt::SystemLocaleShortDate));

    }

    if(search=="劳动感谢日")
    {
        QDate date(year,11,23);
        ui->label->setText(date.toString(Qt::SystemLocaleShortDate));

    }

    if(search=="天皇诞辰日")
    {
        QDate date(year,12,23);
        ui->label->setText(date.toString(Qt::SystemLocaleShortDate));

    }

    if(search=="成人之日")
    {
        QDate datem1temp(year,1,1);//adult day
        int flag1=datem1temp.dayOfWeek();
        switch (flag1) {
        case 1:
        {
            QDate datem1(year,1,8);
            ui->label->setText(datem1.toString(Qt::SystemLocaleShortDate));
            break;
        }
        case 2:
        {
            QDate datem1(year,1,14);
            ui->label->setText(datem1.toString(Qt::SystemLocaleShortDate));
            break;
        }
        case 3:
        {
            QDate datem1(year,1,13);
            ui->label->setText(datem1.toString(Qt::SystemLocaleShortDate));
            break;
        }
        case 4:
        {
            QDate datem1(year,1,12);
            ui->label->setText(datem1.toString(Qt::SystemLocaleShortDate));
            break;
        }
        case 5:
        {
            QDate datem1(year,1,11);
            ui->label->setText(datem1.toString(Qt::SystemLocaleShortDate));
            break;
        }
        case 6:
        {
            QDate datem1(year,1,10);
            ui->label->setText(datem1.toString(Qt::SystemLocaleShortDate));
            break;
        }
        case 7:
        {
            QDate datem1(year,1,9);
            ui->label->setText(datem1.toString(Qt::SystemLocaleShortDate));
            break;
        }
        default:
            break;
        }



    }

    if(search=="海之日")
    {
        QDate datem7temp(year,7,1);//sea day
        int flag3=datem7temp.dayOfWeek();
        switch (flag3) {
        case 1:
        {
            QDate datem1(year,7,15);
            ui->label->setText(datem1.toString(Qt::SystemLocaleShortDate));
            break;
        }
        case 2:
        {
            QDate datem1(year,7,21);
            ui->label->setText(datem1.toString(Qt::SystemLocaleShortDate));
            break;
        }
        case 3:
        {
            QDate datem1(year,7,20);
            ui->label->setText(datem1.toString(Qt::SystemLocaleShortDate));
            break;
        }
        case 4:
        {
            QDate datem1(year,7,19);
            ui->label->setText(datem1.toString(Qt::SystemLocaleShortDate));
            break;
        }
        case 5:
        {
            QDate datem1(year,7,18);
            ui->label->setText(datem1.toString(Qt::SystemLocaleShortDate));
            break;
        }
        case 6:
        {
            QDate datem1(year,7,17);
            ui->label->setText(datem1.toString(Qt::SystemLocaleShortDate));
            break;
        }
        case 7:
        {
            QDate datem1(year,7,16);
            ui->label->setText(datem1.toString(Qt::SystemLocaleShortDate));
            break;
        }
        default:
            break;
        }



    }

    if(search=="体育之日")
    {
        QDate datem10temp(year,10,1);//sports day
        int flag2=datem10temp.dayOfWeek();
        switch (flag2) {
        case 1:
        {
            QDate datem1(year,10,8);
            ui->label->setText(datem1.toString(Qt::SystemLocaleShortDate));
            break;
        }
        case 2:
        {
            QDate datem1(year,10,14);
            ui->label->setText(datem1.toString(Qt::SystemLocaleShortDate));
            break;
        }
        case 3:
        {
            QDate datem1(year,10,13);
            ui->label->setText(datem1.toString(Qt::SystemLocaleShortDate));
            break;
        }
        case 4:
        {
            QDate datem1(year,10,12);
            ui->label->setText(datem1.toString(Qt::SystemLocaleShortDate));
            break;
        }
        case 5:
        {
            QDate datem1(year,10,11);
            ui->label->setText(datem1.toString(Qt::SystemLocaleShortDate));
            break;
        }
        case 6:
        {
            QDate datem1(year,10,10);
            ui->label->setText(datem1.toString(Qt::SystemLocaleShortDate));
            break;
        }
        case 7:
        {
            QDate datem1(year,10,9);
            ui->label->setText(datem1.toString(Qt::SystemLocaleShortDate));
            break;
        }
        default:
            break;
        }

    }
}
