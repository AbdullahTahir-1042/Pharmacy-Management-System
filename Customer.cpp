#include <iostream>
#include "Customer.h"
int Customer::ID = 1;

Customer::Customer()
{
    customer_id = 0, membership_status = false;
}

Customer::Customer(const Customer &other)
{
    customer_id = ID++;
    general_info = other.general_info;
    membership_status = other.membership_status;
    payment_method = other.payment_method;
}

Customer::Customer(const General_info &info, bool membership, const string &payment)
{
    customer_id = ID++;
    general_info = info;
    membership_status = membership;
    payment_method = payment;
}
Customer::~Customer() {}

int Customer::getCustomerID() const
{
    return customer_id;
}

General_info Customer::getGeneralInfo() const
{
    return general_info;
}
void Customer::setGeneralInfo(const General_info &info)
{

    general_info = info;
}

bool Customer::getMembershipStatus() const
{
    return membership_status;
}
void Customer::setMembershipStatus(bool status)
{
    membership_status = status;
}

string Customer::getPaymentMethod() const
{
    return payment_method;
}
void Customer::setPaymentMethod(const string &payment)
{
    payment_method = payment;
}

void Customer::display() const
{
    cout << "Customer ID: " << customer_id << endl;
    cout << "Membership Status: " << (membership_status ? "Member" : "Non-member") << endl;
    cout << "Payment Method: " << payment_method << endl;
    cout << "General Information:" << endl;
    general_info.display();
}

Customer &Customer::operator=(const Customer &other)
{
    if (this != &other)
    {
        customer_id = other.customer_id;
        general_info = other.general_info;
        membership_status = other.membership_status;
        payment_method = other.payment_method;
    }
    return *this;
}

ostream &operator<<(ostream &os, const Customer &customer)
{
    os << "Customer ID: " << customer.customer_id << ", Payment Method: " << customer.payment_method;
    return os;
}

istream &operator>>(istream &is, Customer &customer)
{
    string payment;
    do
    {
        cout << "Enter Payment Method: ";
        is >> payment;
        if (payment == "")
        {
            cerr << "Payment cannot be null" << endl;
        }
        else
        {
            customer.payment_method = payment;
        }
    } while (payment == "");

    return is;
}
