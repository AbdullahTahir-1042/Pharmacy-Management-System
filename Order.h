#ifndef ORDER_H
#define ORDER_H


#include "Date.h"
#include "Medication.h"
#include "Salesman.h"
#include "PharmaCompany.h"
#include "Customer.h"

class Order
{
private:
    int order_id;
    Customer customer;
    Date order_date;
    vector<Medication> bought_medicines;
    Salesman salesman;
    PharmaCompany company;
    double total_amount;

public:
    static int ID;
    Order();
    Order(Order &other);
    Order(const Customer &customer, const Date &date, const vector<Medication> &medicines, const Salesman &salesman, const PharmaCompany &company, double amount);
    ~Order();

    int getOrderID() const;

    Customer getCustomer() const;
    void setCustomer(const Customer &customer);

    Date getOrderDate() const;
    void setOrderDate(const Date &date);

    vector<Medication> getBoughtMedicines() const;
    void setBoughtMedicines(const vector<Medication> &medicines);

    Salesman getSalesman() const;
    void setSalesman(const Salesman &salesman);

    PharmaCompany getCompany() const;
    void setCompany(const PharmaCompany &company);
    int getcustomerId();
    int getMedicationID(int index);

    double getTotalAmount() const;
    void setTotalAmount(double amount);

    friend ostream &operator<<( ostream &os, Order &order);
    friend istream &operator>>( istream &is, Order &order);

    void display();
};
#endif