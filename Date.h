#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;
class Date
{
private:
    int day, month, year;

public:
    Date();
    Date(int day, int month, int year);
    Date(const Date &d);
    ~Date();

    Date operator+(Date &t);
    Date operator-(Date &t);
    int getYear();
    int getMonth();
    int getDay();

    Date &operator=(const Date &d);
    bool operator==(const Date &d);
    void display();

    friend istream &operator>>(istream &i, Date &d);
    friend ostream &operator<<(ostream &o, Date &d);
};
#endif