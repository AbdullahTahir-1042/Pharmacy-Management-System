#include <iostream>
#include "Address.h"

vector<string> Address::used_mobile_numbers;

Address::Address()
{
    city_name = "", email = "", street_name = "";
}

Address::Address(const Address &other)
{
    this->city_name = other.city_name;
    this->email = other.email;
    this->street_name = other.street_name;
    this->mobile_numbers = other.mobile_numbers;
}

Address::Address(const string &city, const string &street, const string &email)
{
    if (city == "")
    {
        cerr << "City cannot be null" << endl;
    }
    else
    {
        city_name = city;
    }

    if (street == "")
    {
        cerr << "Street cannot be null" << endl;
    }
    else
    {
        street_name = street;
    }
    if (!isEmailUnique(email))
    {
        cerr << "Email already Exits." << endl;
    }
    else
    {
        this->email = email;
    }
}

Address::~Address()
{
}

bool Address::isEmailUnique(const string &email)
{
    for (const auto &used_email : used_emails)
    {
        if (used_email == email)
        {
            return false;
        }
    }
    return true;
}

string Address::getCityName() const
{
    return city_name;
}
void Address::setCityName(const string &city)
{
    city_name = city;
}

string Address::getEmail() const
{
    return email;
}
void Address::setEmail(const string &email)
{
    this->email = email;
}

string Address::getStreetName() const
{
    return street_name;
}
void Address::setStreetName(const string &street)
{
    street_name = street;
}

string Address::operator[](int index) const
{
    if (index >= 0 && index < mobile_numbers.size())
        return mobile_numbers[index];
    else
        throw out_of_range("Invalid Index.");
}

void Address::display() const
{
    cout << "City: " << city_name << endl;
    cout << "Street: " << street_name << endl;
    cout << "Email: " << email << endl;
    cout << "Mobile Numbers:" << endl;
    for (int i = 0; i < mobile_numbers.size(); ++i)
    {
        cout << mobile_numbers[i] << endl;
    }
}

ostream &operator<<(ostream &o, const Address &addr)
{
    o << "City: " << addr.city_name << ", Email: " << addr.email;
    return o;
}

istream &operator>>(istream &in, Address &addr)
{
    string city, street, email;

    do
    {
        cout << "Enter city: ";
        in >> addr.city_name;
        if (city == "")
        {
            cerr << "City cannot be null" << endl;
        }
        else
        {
            addr.city_name = city;
        }
    } while (city == "");

    do
    {
        cout << "Enter street name: ";
        in >> addr.street_name;
        if (street == "")
        {
            cerr << "City cannot be null" << endl;
        }
        else
        {
            addr.street_name = street;
        }
    } while (street == "");

    if (street == "")
    {
        cerr << "Street cannot be null" << endl;
    }
    else
    {
        addr.street_name = street;
    }

    do
    {
        cout << "Enter email: ";
        cin >> email;
    } while (email == "");

    if (addr.isEmailUnique(email))
    {
        addr.email = email;
    }
    else
    {
        cerr << "Email already Exits." << endl;
    }

    return in;
}

void Address::addMobileNumber(const string &number)
{
    if (isMobileNumberUnique(number))
    {
        mobile_numbers.push_back(number);
        used_mobile_numbers.push_back(number);
    }
    else
    {
        cerr << "Mobile number already exists." << endl;
    }
}

bool Address::isMobileNumberUnique(const string &number) const
{
    for (const auto &used_number : used_mobile_numbers)
    {
        if (used_number == number)
        {
            return false;
        }
    }
    return true;
}
