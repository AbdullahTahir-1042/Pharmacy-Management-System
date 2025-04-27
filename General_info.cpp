#include <iostream>
#include "General_info.h"

General_info::General_info()
{
    first_name = "";
    last_name = "";
    cnic = "";
    address = Address();
}

General_info::General_info(const General_info &other)
{
    first_name = other.first_name;
    last_name = other.last_name;
    cnic = other.cnic;
    address = other.address;
    {
        for (int i = 0; i < 2; ++i)
        {
            gender[i] = other.gender[i];
        }
    }
}

General_info::General_info(const string &first, const string &last, string &cnic, const Address &addr, const string gender[])
{
    if (first == "")
    {
        cerr << "Name cannot be null" << endl;
    }
    else
    {
        first_name = first;
    }

    if (last == "")
    {
        cerr << "Name cannot be null" << endl;
    }
    else
    {
        last_name = last;
    }

    address = addr;
    if (cnic.length() != 13 || !isDigit(cnic))
    {
        cerr << "Invalid CNIC." << endl;
    }
    else
    {
        this->cnic = cnic;
    }
}

General_info::~General_info() {}

bool isDigit(string &s)
{
    for (auto &c : s)
    {
        if (c < 0 && c > 9)
        {
            return false;
        }
    }
    return true;
}

string General_info::getFirstName() const
{
    return first_name;
}
void General_info::setFirstName(const string &first)
{
    first_name = first;
}

string General_info::getLastName() const
{
    return last_name;
}
void General_info::setLastName(const string &last)
{
    last_name = last;
}

string General_info::getCNIC() const
{
    return cnic;
}
void General_info::setCNIC(string &cnic)
{
    if (cnic.length() != 13 || !isDigit(cnic))
    {
        cerr << "Invalid CNIC." << endl;
    }
    this->cnic = cnic;
}

Address General_info::getAddress() const
{
    return address;
}
void General_info::setAddress(const Address &addr)
{
    address = addr;
}

string General_info::getGender(int index) const
{
    if (index >= 0 && index < 2)
        return gender[index];
    else
        return "";
}

void General_info::setGender(const string &gender, int index)
{
    if (index >= 0 && index < 2)
        this->gender[index] = gender;
    else
        cerr << "Invalid gender index." << endl;
}

void General_info::display() const
{
    cout << "First Name: " << first_name << endl;
    cout << "Last Name: " << last_name << endl;
    cout << "CNIC: " << cnic << endl;
    cout << "Gender: " << gender[0] << ", " << gender[1] << endl;
    cout << "Address:" << endl;
    address.display();
}

General_info &General_info::operator=(const General_info &other)
{
    if (this != &other)
    {
        first_name = other.first_name;
        last_name = other.last_name;
        cnic = other.cnic;
        address = other.address;
        for (int i = 0; i < 2; ++i)
        {
            gender[i] = other.gender[i];
        }
    }
    return *this;
}

ostream &operator<<(ostream &os, const General_info &info)
{
    os << "First Name: " << info.first_name
       << ", Last Name: " << info.last_name
       << ", CNIC: " << info.cnic
       << ", Gender: " << info.gender[0] << ", " << info.gender[1]
       << ", Address: " << info.address;  // Assumes Address has operator<< implemented
    return os;
}


istream &operator>>(istream &is, General_info &info)
{
    string first, last, cnic;
    do
    {
        cout << "Enter First Name: ";
        is >> info.first_name;
        if (first == "")
        {
            cerr << "Name cannot be null" << endl;
        }
        else
        {
            info.first_name = first;
        }
    } while (first == "");

    do
    {
        cout << "Enter last name: ";
        is >> last;
        if (last == "")
        {
            cerr << "Name cannot be null" << endl;
        }
        else
        {
            info.last_name = last;
        }
    } while (last == "");

    do
    {
        cout << "Enter CNIC (13 digits): ";
        is >> cnic;
        if (info.cnic.length() != 13 || !isDigit(info.cnic))
        {
            cerr << "Invalid CNIC." << endl;
            throw invalid_argument("Invalid CNIC.");
        }
        else
        {
            info.cnic = cnic;
        }

    } while (info.cnic.length() != 13 || !isDigit(info.cnic));

    return is;
}
