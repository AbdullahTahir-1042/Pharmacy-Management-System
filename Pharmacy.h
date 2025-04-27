#ifndef PHARMACY_H
#define PHARMACY_H

#include <string>
#include "Medication.h"
#include "Customer.h"
#include "Staff.h"
#include "Salesman.h"
#include "Order.h"

class Pharmacy
{
private:
    static int next_id;
    int pharmacy_id;
    string pharmacy_name;
    string pharmacy_owner;
    Medication *medications;
    int max_medication_size;
    int current_medication_size;
    int *medication_quantity;
    Staff *staffs;
    int max_staff_size;
    int current_staff_size;
    Salesman *salesmen;
    int max_salesman_size;
    int current_salesman_size;
    Order *orders;
    int max_orders_size;
    int current_orders_size;
    double total_sales;
    double total_purchases;
    double total_profit;

public:
    Pharmacy();
    Pharmacy(const string &name, const string &owner, int maxMedSize, int maxStaffSize, int maxSalesmanSize, int maxOrdersSize);
    Pharmacy(const Pharmacy &other);
    ~Pharmacy();

    Pharmacy &operator=(const Pharmacy &other);

    void addMedication(const Medication &medication, int quantity);
    void removeMedication(int medicationID);
    void updateMedicationDetails(int medicationID, const Medication &newMedication);

    void addOrder(const Order &order);
    void displayOrders() const;

    void addStaff(const Staff &staff);
    void removeStaff(int staffID);
    void displayStaff() const;

    void addSalesman(const Salesman &salesman);
    void removeSalesman(int salesmanID);
    void displaySalesmen() const;

    double getTotalPurchases() const;
    void setTotalPurchases(double purchases);
    double getTotalSales() const;
    void setTotalSales(double sales);
    double getTotalProfit() const;
    void setTotalProfit(double profit);
    void displayMedicines() const;

    void display() const;

    void sellMedicine(Pharmacy &customer);
    void purchaseMedicine(const Salesman &salesman);

    void showOrdersByCustomer(int id) const;
    void showOrdersByMedicine(int id) const;
    void showOrdersByDate(Date &date) const;

    void payStaffSalary();

    void discardExpiryMedicine();

};
#endif