#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Address
{
private:
    string city_name;
    string email;
    string street_name;
    vector<string> mobile_numbers;

public:
    static vector<string> used_mobile_numbers;
    static vector<string> used_emails;
    Address();
    Address(const Address &other);
    Address(const string &city, const string &street, const string &email);
    ~Address();

    string getCityName() const;
    void setCityName(const string &city);

    string getEmail() const;
    void setEmail(const string &email);

    string getStreetName() const;
    void setStreetName(const string &street);

    string operator[](int index) const;

    void display() const;

    friend ostream &operator<<(ostream &o, const Address &addr);
    friend istream &operator>>(istream &in, Address &addr);

    void addMobileNumber(const string &number);

    bool isMobileNumberUnique(const string &number) const;
    bool isEmailUnique(const string &email);
};
#endif 