#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include "General_info.h"

class Customer
{
private:
    int customer_id;
    General_info general_info;
    bool membership_status;
    string payment_method;

public:
    static int ID;
    Customer();
    Customer(const Customer &other);
    Customer( const General_info &info, bool membership, const string &payment);
    ~Customer();

    int getCustomerID() const;
    void setCustomerID(int id);

    General_info getGeneralInfo() const;
    void setGeneralInfo(const General_info &info);

    bool getMembershipStatus() const;
    void setMembershipStatus(bool status);

    string getPaymentMethod() const;
    void setPaymentMethod(const string &payment);

    void display() const;

    Customer &operator=(const Customer &other);
    friend ostream &operator<<(ostream &os, const Customer &customer);
    friend istream &operator>>(istream &is, Customer &customer);
};
#endif