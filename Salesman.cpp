#include <iostream>
#include "Salesman.h"

int Salesman::id = 1;

Salesman::Salesman()
{
    salesman_id = id++;
    general_info = General_info();
    pharma_company = PharmaCompany();
    set_commission = 0.0;
    obtained_commission = 0.0;
}

Salesman::Salesman(const General_info &info, const PharmaCompany &company, double commission)
{
    salesman_id = id++;
    general_info = info;
    pharma_company = company;
    set_commission = commission;
    obtained_commission = 0.0;
}

Salesman::~Salesman() {}

int Salesman::getSalesmanID() const
{
    return salesman_id;
}
void Salesman::setSalesmanID(int id)
{
    salesman_id = id;
}

General_info Salesman::getGeneralInfo() const
{
    return general_info;
}
void Salesman::setGeneralInfo(const General_info &info)
{
    general_info = info;
}

PharmaCompany Salesman::getPharmaCompany() const
{
    return pharma_company;
}
void Salesman::setPharmaCompany(const PharmaCompany &company)
{
    pharma_company = company;
}

double Salesman::getSetCommission() const
{
    return set_commission;
}
void Salesman::setSetCommission(double commission)
{
    set_commission = commission;
}

double Salesman::getObtainedCommission() const
{
    return obtained_commission;
}
void Salesman::setObtainedCommission(int n, double prize)
{
    obtained_commission = calculateCommision(n, prize);
}

void Salesman::display() const
{
    cout << "Salesman ID: " << salesman_id << endl;
    cout << "General Information:" << endl;
    general_info.display();
    cout << "Pharma Company Information:" << endl;
    pharma_company.display();
    cout << "Set Commission: $" << set_commission << endl;
    cout << "Obtained Commission: $" << obtained_commission << endl;
}

void Salesman::addCommission(double commission)
{
    obtained_commission += commission;
}

void Salesman::showCompanyMedicines() const
{
    cout << "Medicines offered by " << pharma_company.getCompanyName() << ":" << endl;
    vector<string> medicines = pharma_company.getMedicineList();
    for (size_t i = 0; i < medicines.size(); ++i)
    {
        cout << i + 1 << ". " << medicines[i] << endl;
    }
}

double Salesman::calculateCommision(int numMedicinesSold, double prize)
{
    return numMedicinesSold * prize * (set_commission / 100);
}

ostream &operator<<(ostream &os, Salesman &salesman)
{
    os << "Salesman ID: " << salesman.salesman_id << endl;
    os << salesman.general_info << endl;
    return os;
}

istream &operator>>(istream &is, Salesman &salesman)
{
    cout << "Enter general Information: ";
    is >> salesman.general_info;
    return is;
}