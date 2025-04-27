#ifndef PHARMACOMPANY_H
#define PHARMACOMPANY_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class PharmaCompany
{
private:
    int company_id;
    string company_name;
    string location;
    vector<string> medicine_list;

public:
    static int id;
    PharmaCompany();
    PharmaCompany(const PharmaCompany &other);
    PharmaCompany(const string &name, const string &loc);
    ~PharmaCompany();

    int getCompanyID() const;
    void setCompanyID(int id);

    string getCompanyName() const;
    void setCompanyName(const string &name);

    string getLocation() const;
    void setLocation(const string &loc);

    vector<string> getMedicineList() const;
    void setMedicineList(const vector<string> &list);

    void display() const;

    PharmaCompany &operator=(const PharmaCompany &other);
    friend ostream &operator<<(ostream &os, const PharmaCompany &company);
    friend istream &operator>>(istream &is, PharmaCompany &company);
};
#endif