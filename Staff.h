#ifndef STAFF_H
#define STAFF_H

#include <iostream>
#include "General_info.h"
#include "Date.h"

class Staff
{
private:
    int staff_id;
    string role;
    Date employment_date;
    General_info general_info;
    double salary;

public:
    static int ID;
    Staff();
    Staff(const Staff &other);
    Staff(const string &role, const Date &employmentDate, const General_info &info, double salary);
    ~Staff();

    int getStaffID() const;
    void setStaffID(int id);

    string getRole() const;
    void setRole(const string &role);

    Date getEmploymentDate() const;
    void setEmploymentDate(const Date &date);

    General_info getGeneralInfo() const;
    void setGeneralInfo(const General_info &info);

    double getSalary() const;
    void setSalary(double salary);

    void display() ;

    Staff &operator=(const Staff &other);
    friend ostream &operator<<(ostream &os,  Staff &staff);
    friend istream &operator>>(istream &is, Staff &staff);
};
#endif
