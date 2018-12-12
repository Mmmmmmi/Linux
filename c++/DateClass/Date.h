#pragma once

#include <iostream>
class Date
{


    friend std::ostream& operator<<(std::ostream& _cout, const Date& d);
    friend std::istream& operator>>(std::istream& _cin, Date& d);

public:
    Date(int year = 1970, int month = 1, int day = 1);
    ~Date();
    Date(const Date& d);
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    Date& operator=(const Date& d);
    Date operator+(int days) const;
    Date& operator+=(int days);
    Date operator-(int days) const;
    Date& operator-=(int days);
    int operator-(const Date& d) const;
    Date& operator++();
    Date operator++(int);
    Date& operator--();
    Date operator--(int);
    Date* operator&();
    const Date* operator&() const;
    bool operator>(const Date& d) const;
    bool operator>=(const Date& d) const;
    bool operator<(const Date& d) const;
    bool operator<=(const Date& d) const;
    bool operator==(const Date& d) const;
    bool operator!=(const Date& d) const; 


private:
    bool isLeapYear() const;
    int getDayInMonth() const;
    int _year;
    int _month;
    int _day;
};

