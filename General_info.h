#ifndef GENERAL_INFO_H
#define GENERAL_INFO_H

#include <iostream>
#include <string>
#include "Address.h"

class  General_info
{
private:
    string first_name;
    string last_name;
    string cnic;
    Address address;
    string gender[2];

public:
     General_info();
     General_info(const  General_info &other);
     General_info(const string &first, const string &last,  string &cnic, const Address &addr, const string gender[]);
    ~ General_info();

    string getFirstName() const;
    void setFirstName(const string &first);

    string getLastName() const;
    void setLastName(const string &last);

    string getCNIC() const;
    void setCNIC(string &cnic);

    Address getAddress() const;
    void setAddress(const Address &addr);

    string getGender(int index) const;
    void setGender(const string &gender, int index);

    void display() const;
    bool isDigit(string n);

     General_info &operator=(const  General_info &other);
    friend ostream &operator<<(ostream &os, const  General_info &info);
    friend istream &operator>>(istream &is,  General_info &info);
};
#endif