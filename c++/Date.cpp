
#include "Date.h"
#include <iostream>


//构造函数
Date::Date(int year, int month, int day)
    :_year(year)
    ,_month(month)
    ,_day(day)
{}

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


