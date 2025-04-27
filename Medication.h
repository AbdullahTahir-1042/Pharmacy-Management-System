#ifndef MEDICATION_H
#define MEDICATION_H


#include <iostream>
#include "Date.h"

class Medication
{
private:
    int medication_id;
    string medication_name;
    string description;
    double price;
    int quantity_in_stock;
    Date expiry_date;
    string company_name;

public:
    static int id;
    Medication();
    Medication(const Medication &other);
    Medication(const string &name, const string &desc, double price, int quantity, const Date &expiry, const string &company);
    ~Medication();

    int getMedicationID() const;
    void setMedicationID(int id);

    string getMedicationName() const;
    void setMedicationName(const string &name);

    string getDescription() const;
    void setDescription(const string &desc);

    double getPrice() const;
    void setPrice(double price);

    int getQuantityInStock() const;
    void setQuantityInStock(int quantity);

    Date getExpiryDate() const;
    void setExpiryDate(const Date &expiry);

    string getCompanyName() const;
    void setCompanyName(const string &company);

    bool isExpired();

    void display();

    Medication &operator=(const Medication &other);
    friend ostream &operator<<(ostream &os, Medication &medication);
    friend istream &operator>>(istream &is, Medication &medication);
};
#endif