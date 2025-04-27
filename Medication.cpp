#include <iostream>
#include "Medication.h"

int Medication::id = 1;

Medication::Medication()
{
    medication_id = id++;
    medication_name = "";
    description = "";
    price = 0.0;
    quantity_in_stock = 0;
    expiry_date = Date();
    company_name = "";
}

Medication::Medication(const Medication &other)
{
    medication_id = other.medication_id;
    medication_name = other.medication_name;
    description = other.description;
    price = other.price;
    quantity_in_stock = other.quantity_in_stock;
    expiry_date = other.expiry_date;
    company_name = other.company_name;
}

Medication::Medication(const string &name, const string &desc, double price, int quantity, const Date &expiry, const string &company)
{
    medication_id = id++;
    medication_name = name;
    description = desc;
    price = price;
    quantity_in_stock = quantity;
    expiry_date = expiry;
    company_name = company;
}

Medication::~Medication() {}

int Medication::getMedicationID() const
{
    return medication_id;
}
void Medication::setMedicationID(int id)
{
    medication_id = id;
}

string Medication::getMedicationName() const
{
    return medication_name;
}
void Medication::setMedicationName(const string &name)
{
    medication_name = name;
}

string Medication::getDescription() const
{
    return description;
}
void Medication::setDescription(const string &desc)
{
    description = desc;
}

double Medication::getPrice() const
{
    return price;
}
void Medication::setPrice(double price)
{
    this->price = price;
}

int Medication::getQuantityInStock() const
{
    return quantity_in_stock;
}
void Medication::setQuantityInStock(int quantity)
{
    quantity_in_stock = quantity;
}

Date Medication::getExpiryDate() const
{
    return expiry_date;
}
void Medication::setExpiryDate(const Date &expiry)
{
    expiry_date = expiry;
}

string Medication::getCompanyName() const
{
    return company_name;
}
void Medication::setCompanyName(const string &company)
{
    company_name = company;
}

bool Medication::isExpired()
{
    Date current_date(7, 5, 2024);

    if (expiry_date.getDay() < current_date.getYear())
        return true;
    else if (expiry_date.getYear() > current_date.getYear())
        return false;

    if (expiry_date.getMonth() < current_date.getMonth())
        return true;
    else if (expiry_date.getMonth() > current_date.getMonth())
        return false;

    if (expiry_date.getDay() < current_date.getDay())
        return true;

    return false;
}

void Medication::display()
{
    cout << "Medication ID: " << medication_id << endl;
    cout << "Medication Name: " << medication_name << endl;
    cout << "Description: " << description << endl;
    cout << "Price: $" << price << endl;
    cout << "Quantity in Stock: " << quantity_in_stock << endl;
    cout << "Expiry Date: " << expiry_date << endl;
    cout << "Company Name: " << company_name << endl;
}

Medication &Medication::operator=(const Medication &other)
{
    if (this != &other)
    {
        medication_id = other.medication_id;
        medication_name = other.medication_name;
        description = other.description;
        price = other.price;
        quantity_in_stock = other.quantity_in_stock;
        expiry_date = other.expiry_date;
        company_name = other.company_name;
    }
    return *this;
}

ostream &operator<<(ostream &os, Medication &medication)
{
    os << "Medication ID: " << medication.medication_id << ", Medication Name: " << medication.medication_name
       << ", Price: $" << medication.price << ", Quantity in Stock: " << medication.quantity_in_stock
       << ", Expiry Date: " << medication.expiry_date;
    return os;
}

istream &operator>>(istream &is, Medication &medication)
{
    string name;
    int n, stock;
    do
    {
        cout << "Enter Medication Name: ";
        is >> name;

    } while (name == "");
    medication.setMedicationName(name);

    do
    {
        cout << "Enter Price: ";
        is >> n;
    } while (n < 0);
    medication.setPrice(n);

    do
    {
        cout << "Enter Quantity in Stock: ";
        is >> stock;
    } while (stock < 0);
    medication.setQuantityInStock(stock);

    cout << "Enter Expiry Date (YYYY-MM-DD): ";
    is >> medication.expiry_date;
    return is;
}
