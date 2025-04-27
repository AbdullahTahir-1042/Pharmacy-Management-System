#include <iostream>
#include "Date.h"

Date::Date()
{
    day = 0;
    month = 0;
    year = 0;
}

Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

Date::Date(const Date &d)
{
    day = d.day;
    month = d.month;
    year = d.year;
}

Date::~Date() {}

Date Date::operator+(Date &t)
{
    Date temp;
    temp.day = day + t.day;
    temp.month = month + t.month;
    temp.year = year + t.year;

    if (temp.day > 30)
    {
        temp.day -= 30;
        temp.month++;
    }
    if (temp.month > 12)
    {
        temp.month -= 12;
        temp.year++;
    }
    return temp;
}

int Date::getDay()
{
    return day;
}

int Date::getMonth()
{
    return month;
}

int Date::getYear()
{
    return year;
}

void Date::display()
{
    cout << day << "-" << month << "-" << year << endl;
}

Date Date::operator-(Date &t)
{
    Date temp;
    temp.day = day - t.day;
    temp.month = month - t.month;
    temp.year = year - t.year;

    if (temp.day < 0)
    {
        temp.day += 30;
        temp.month--;
    }
    if (temp.month < 0)
    {
        temp.month += 12;
        temp.year--;
    }
    return temp;
}

Date &Date::operator=(const Date &d)
{
    day = d.day;
    month = d.month;
    year = d.year;
    return *this;
}

bool Date::operator==(const Date &d)
{
    if (year == d.year)
    {
        if (month == d.month)
        {
            if (day == d.day)
            {
                return true;
            }
        }
    }
    return false;
}

istream &operator>>(istream &i, Date &d)
{
    do
    {
        cout << "Enter day: ";
        i >> d.day;
    } while (d.day <= 0 || d.day > 30);

    do
    {
        cout << "Enter Month: ";
        i >> d.month;
    } while (d.month <= 0 || d.month > 12);

    do
    {
        cout << "Enter year: ";
        i >> d.year;
    } while (d.year <= 0 || d.day > 3000);

    return i;
}

ostream &operator<<(ostream &o, Date &d)
{
    o << d.day << "-" << d.month << "-" << d.year << endl;
    return o;
}
