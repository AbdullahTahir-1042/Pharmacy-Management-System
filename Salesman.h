#ifndef SALESMAN_H
#define SALESMAN_H

#include <iostream>
#include <vector>
#include "General_info.h"
#include "PharmaCompany.h"

class Salesman
{
private:
    int salesman_id;
    General_info general_info;
    PharmaCompany pharma_company;
    double set_commission;
    double obtained_commission;

public:
    static int id;
    Salesman();
    Salesman(const General_info &info, const PharmaCompany &company, double commission);
    ~Salesman();

    int getSalesmanID() const;
    void setSalesmanID(int id);

    General_info getGeneralInfo() const;
    void setGeneralInfo(const General_info &info);

    PharmaCompany getPharmaCompany() const;
    void setPharmaCompany(const PharmaCompany &company);

    double getSetCommission() const;
    void setSetCommission(double commission);

    double getObtainedCommission() const;
    void setObtainedCommission(int n, double prize);

    void display() const;

    void addCommission(double commission);

    void showCompanyMedicines() const;

    friend  ostream& operator<<( ostream& os, Salesman& salesman);
    friend  istream& operator>>( istream& is, Salesman& salesman);


    double calculateCommision(int sales, double prize);
};
#endif