#include <iostream>
#include "PharmaCompany.h"

int PharmaCompany::id = 1;

PharmaCompany::PharmaCompany()
{
    company_id = id++;
    company_name = "";
    location = "";
    medicine_list.push_back("Paracetamol");
    medicine_list.push_back("Panadol");
    medicine_list.push_back("Nims");
    medicine_list.push_back("Strepcils");
}

PharmaCompany::PharmaCompany(const PharmaCompany &other)
{
    company_id = other.company_id;
    company_name = other.company_name;
    location = other.location;
    medicine_list = other.medicine_list;
}

PharmaCompany::PharmaCompany(const string &name, const string &loc)
{
    company_id = id++;
    company_name = name;
    location = loc;
    medicine_list.push_back("Paracetamol");
    medicine_list.push_back("Panadol");
    medicine_list.push_back("Nims");
    medicine_list.push_back("Strepcils");
}

PharmaCompany::~PharmaCompany() {}

int PharmaCompany::getCompanyID() const
{
    return company_id;
}
void PharmaCompany::setCompanyID(int id)
{
    company_id = id;
}

string PharmaCompany::getCompanyName() const
{
    return company_name;
}
void PharmaCompany::setCompanyName(const string &name)
{
    company_name = name;
}

string PharmaCompany::getLocation() const
{
    return location;
}
void PharmaCompany::setLocation(const string &loc)
{
    location = loc;
}

vector<string> PharmaCompany::getMedicineList() const
{
    return medicine_list;
}
void PharmaCompany::setMedicineList(const vector<string> &list)
{
    medicine_list = list;
}

void PharmaCompany::display() const
{
    cout << "Company ID: " << company_id << endl;
    cout << "Company Name: " << company_name << endl;
    cout << "Location: " << location << endl;
}

PharmaCompany &PharmaCompany::operator=(const PharmaCompany &other)
{
    if (this != &other)
    {
        company_id = other.company_id;
        company_name = other.company_name;
        location = other.location;
        medicine_list = other.medicine_list;
    }
    return *this;
}

ostream &operator<<(ostream &os, const PharmaCompany &company)
{
    os << "Company ID: " << company.company_id << ", Company Name: " << company.company_name << ", Location: " << company.location;
    return os;
}

istream &operator>>(istream &is, PharmaCompany &company)
{
    string name, loc;
    do
    {
        cout << "Enter Company Name: ";
        is >> name;
    } while (name == "");
    company.setCompanyName(name);

    do
    {
        cout << "Enter Location: ";
        is >> loc;
    } while (loc == "");
    company.setLocation(loc);

    return is;
}
