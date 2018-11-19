#pragma once

class Date
{
public:
    Date(int year = 1970, int month = 1, int day = 1);
    ~Date();
    Date(const Date& d);
    Date& operator=(const Date& d);
    Date operator+(int days);
    Date operator+=(int days);
    Date operator-(int days);
    Date operator-=(int days);
    int operator-(const Date& d);
    Date& operator++();
    Date operator++(int);
    Date& operator--();
    Date operator--(int);
    bool operator>(const Date& d);
    bool operator>=(const Date& d);
    bool operator<(const Date& d);
    bool operator<=(const Date& d);
    bool operator==(const Date& d);
    bool operator!=(const Date& d); 


private:
    int _year;
    int _month;
    int _day;
};

