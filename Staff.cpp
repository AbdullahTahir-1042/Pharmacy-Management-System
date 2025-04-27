#include<iostream>
#include "Staff.h"

int Staff::ID = 1;

Staff::Staff()
{
    staff_id = ID++;
    role = "";
    employment_date = Date();
    salary = 0.0;
}

Staff::Staff(const Staff &other)
{
    staff_id = other.staff_id;
    role = other.role;
    employment_date = other.employment_date;
    general_info = other.general_info;
    salary = other.salary;
}

Staff::Staff(const string &role, const Date &employmentDate, const General_info &info, double salary)
{
    staff_id = ID++;
    this->role = role;
    employment_date = employmentDate;
    general_info = info;
    this->salary = salary;
}

Staff::~Staff() {}

int Staff::getStaffID() const
{
    return staff_id;
}

string Staff::getRole() const
{
    return role;
}
void Staff::setRole(const string &role)
{
    this->role = role;
}

Date Staff::getEmploymentDate() const
{
    return employment_date;
}
void Staff::setEmploymentDate(const Date &date)
{
    employment_date = date;
}

General_info Staff::getGeneralInfo() const
{
    return general_info;
}
void Staff::setGeneralInfo(const General_info &info)
{
    general_info = info;
}

double Staff::getSalary() const
{
    return salary;
}
void Staff::setSalary(double salary)
{
    this->salary = salary;
}

void Staff::display()
{
    cout << "Staff ID: " << staff_id << endl;
    cout << "Role: " << role << endl;
    cout << "Employment Date: ";
    employment_date.display();
    cout << "Salary: $" << salary << endl;
    cout << "General Information:" << endl;
    general_info.display();
}

Staff &Staff::operator=(const Staff &other)
{
    if (this != &other)
    {
        staff_id = other.staff_id;
        role = other.role;
        employment_date = other.employment_date;
        general_info = other.general_info;
        salary = other.salary;
    }
    return *this;
}

ostream &operator<<(ostream &os, Staff &staff)
{
    os << "Staff ID: " << staff.staff_id << ", Role: " << staff.role << ", Employment Date: " << staff.employment_date;
    return os;
}

istream &operator>>(istream &is, Staff &staff)
{
    string role;
    do
    {
        cout << "Enter Role: ";
        is >> role;
    } while (role == "");
    staff.setRole(role);

    cout << "Enter Employment Date (DD-MM-YYYY): ";
    is >> staff.employment_date;
    return is;
}
