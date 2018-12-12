#include "Date.h"
#include <assert.h>
#include <iostream>

//构造函数
Date::Date(int year, int month, int day)
    :_year(year)
    ,_month(month)
    ,_day(day)
{
    assert(this->_month < 13 && this->_month > 0
        && this->_day > 0 && this->_day < getDayInMonth());
}

//析构函数
Date::~Date()
{
    _year = 0;
    _month = 0;
    _day = 0;
}


//拷贝构造函数
Date::Date(const Date& d)
    :_year(d._year)
     ,_month(d._month)
     ,_day(d._day)
{}


//返回年份
int Date::getYear() const
{
    return this->_year;
}


//返回月份
int Date::getMonth() const
{
    return this->_month;
}


//返回日期
int Date::getDay() const
{
    return this->_day;
}

//赋值运算符重载
Date& Date::operator=(const Date& d)
{
    if (this != &d) {
        this->_year = d._year;
        this->_month = d._month;
        this->_day = d._day;
    }
    return *this;
}

//判断年份是否是闰年
bool Date::isLeapYear() const
{
    return (this->_year % 400 == 0) || ((this->_year % 4 == 0) && (this->_year % 100 != 0));
}


//判断日期的合法性
int Date::getDayInMonth() const
{
    int daynumber[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (this->isLeapYear()) {
        daynumber[1] = 29;
    }
    return daynumber[this->_month - 1];
}



//+运算符重载
Date Date::operator+(int days) const
{
    Date temp(*this); 
    if (days < 0) {
        return temp - (-days);
    }
    temp._day += days;
    while(temp._day > temp.getDayInMonth()) {        //日期不合法 
        temp._day -= temp.getDayInMonth();
        temp._month++;
        if (temp._month > 12) {
            temp._year++;
            temp._month = 1;
        }
    }
    return temp;
}

//+=运算符重载
Date& Date::operator+=(int days)
{
    (*this) = (*this) + days;
    return *this;
}


//-运算符重载
Date Date::operator-(int days) const
{
    Date temp(*this);
    if (days < 0) {
        return temp + (-days);
    }
    temp._day -= days;
    while(temp._day < 1) {
        temp._month--;
        if (temp._month < 1) {
            temp._year--;
            temp._month = 12;
        }
        temp._day += temp.getDayInMonth();
    }
    return temp;
}


//-=运算符重载
Date& Date::operator-=(int days)
{
    (*this) = (*this) - days;
    return *this;
}


//<<运算符重载
std::ostream& operator<<(std::ostream& _cout, const Date& d)
{
    _cout<< d._year<< "-"<< d._month<< "-"<< d._day;
    return _cout;
}


//>>运算符重载
std::istream& operator>>(std::istream& _cin, Date& d)
{
    _cin>> d._year>> d._month>> d._day;
    return _cin;
}

//前置++运算符重载
Date& Date::operator++()
{
    (*this) += 1;
    return (*this);
}

//后置++运算符重载
Date Date::operator++(int)
{
    Date temp(*this);
    (*this) += 1;
    return temp;
}

//前置--运算符重载
Date& Date::operator--()
{
    (*this) -= 1;
    return (*this);
}

//后置++运算符重载
Date Date::operator--(int)
{
    Date temp(*this);
    (*this) -= 1;
    return temp;
}

//-运算符重载
int Date::operator-(const Date& d) const
{
    int ret = 0;
    Date mindate;
    Date maxdate;
    if ((*this) == d) {
        return 0;
    }
    mindate = (*this) < d ? (*this) : d;
    maxdate = (*this) > d ? (*this) : d;
    while(1) {
        if (mindate + ret == maxdate) {
            break;
        }
        ++ret;
    }
    return ret;
}

//&运算符重载
Date* Date::operator&()
{
    return this;
}

//&运算符重载   针对const 对象
const Date* Date::operator&() const
{
    return this;
}

//>运算符重载
bool Date::operator>(const Date& d) const
{
    return (this->_year > d._year)
        || (this->_year == d._year && this->_month > d._month)
        || (this->_year == d._year && this->_month == d._month && this->_day > d._day);
}

//>=运算符重载
bool Date::operator>=(const Date& d) const
{
    return (*this) > d || (*this) == d;
}


//>运算符重载
bool Date::operator<(const Date& d) const
{
    return (this->_year < d._year)
        || (this->_year == d._year && this->_month < d._month)
        || (this->_year == d._year && this->_month == d._month && this->_day < d._day);
}


//>=运算符重载
bool Date::operator<=(const Date& d) const
{
    return (*this) < d || (*this) == d;
}

//==运算符重载
bool Date::operator==(const Date& d) const
{
    return this->_year == d._year 
        && this->_month == d._month 
        && this->_day == d._day;
}

//!=运算符重载
bool Date::operator!=(const Date& d) const
{
    return this->_year != d._year 
        || this->_month != d._month
        || this->_day != d._day;
}
