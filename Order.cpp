#include <iostream>
#include "Order.h"

int Order::ID = 1;

Order::Order()
{

    order_id = ID++;
    customer = Customer();
    order_date = Date();
    total_amount = 0.0;
}

Order::Order(const Customer &customer, const Date &date, const vector<Medication> &medicines, const Salesman &salesman, const PharmaCompany &company, double amount)
{
    order_id = ID++;
    this->customer = customer;
    order_date = date;
    this->bought_medicines = medicines;
    this->salesman = salesman;
    this->company = company;
    total_amount = amount;
}

Order::Order(Order &other)
{
    order_id = other.order_id;
    customer = other.customer;
    order_date = other.order_date;
    bought_medicines = other.bought_medicines;
    salesman = other.salesman;
    company = other.company;
    total_amount = other.total_amount;
}

Order::~Order() {}

int Order::getOrderID() const
{
    return order_id;
}

Customer Order::getCustomer() const
{
    return customer;
}
void Order::setCustomer(const Customer &customer)
{
    this->customer = customer;
}

Date Order::getOrderDate() const
{
    return order_date;
}
void Order::setOrderDate(const Date &date)
{
    order_date = date;
}

vector<Medication> Order::getBoughtMedicines() const
{
    return bought_medicines;
}
void Order::setBoughtMedicines(const vector<Medication> &medicines)
{
    bought_medicines = medicines;
}

Salesman Order::getSalesman() const
{
    return salesman;
}

void Order::setSalesman(const Salesman &salesman)
{
    this->salesman = salesman;
}

PharmaCompany Order::getCompany() const
{
    return company;
}
void Order::setCompany(const PharmaCompany &company)
{
    this->company = company;
}

double Order::getTotalAmount() const
{
    return total_amount;
}
void Order::setTotalAmount(double amount)
{
    total_amount = amount;
}

void Order::display()
{
    cout << "Order ID: " << order_id << endl;
    cout << "Customer ID: " << customer.getCustomerID() << endl;
    cout << "Order Date: " << order_date << endl;
    cout << "Bought Medicines: " << endl;
    for (auto &medicine : bought_medicines)
    {
        cout << medicine << endl;
    }
    cout << "Salesman: " << salesman.getSalesmanID() << endl;
    cout << "Pharma Company: " << company.getCompanyName() << endl;
    cout << "Total Amount: $" << total_amount << endl;
    cout << "Payment Method: " << customer.getPaymentMethod() << endl;
}

int Order::getcustomerId()
{
    return customer.getCustomerID();
}

int Order::getMedicationID(int index)
{
    return bought_medicines[index].getMedicationID();
}

ostream &operator<<(ostream &os, Order &order)
{
    os << "Order ID: " << order.order_id << endl;
    os << "Customer details" << endl;
    os << order.customer;
    os << "Order Date: " << order.order_date << endl;
    os << "Salesman details" << endl;
    os << order.salesman;
    os << "Total Amount: " << order.total_amount << endl;
    os << "Bought Medicines:" << endl;
    for (int i = 0; i < order.bought_medicines.size(); ++i)
    {
        os << order.bought_medicines[i] << endl;
    }
    return os;
}

istream &operator>>(istream &is, Order &order)
{
    cout << "Enter Order Date (dd mm yyyy): ";
    is >> order.order_date;
    cout << "Enter Salesman Details:" << endl;
    is >> order.salesman;
    cout << "Enter Customer details: ";
    is >> order.customer;
    cout << "Enter Total Amount: ";
    is >> order.total_amount;
    return is;
}
