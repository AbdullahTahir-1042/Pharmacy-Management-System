#include "Pharmacy.h"
#include <iostream>

Pharmacy::Pharmacy()
{
    pharmacy_id = next_id++;
    pharmacy_name = "";
    pharmacy_owner = "";
    max_medication_size = 100;
    current_medication_size = 0;
    max_staff_size = 50;
    current_staff_size = 0;
    max_salesman_size = 30;
    current_salesman_size = 0;
    max_orders_size = 200;
    current_orders_size = 0;
    total_sales = 0;
    total_purchases = 0;
    total_profit = 0;
    medications = new Medication[max_medication_size];
    medication_quantity = new int[max_medication_size];
    staffs = new Staff[max_staff_size];
    salesmen = new Salesman[max_salesman_size];
    orders = new Order[max_orders_size];
}

Pharmacy::Pharmacy(const string &name, const string &owner, int maxMedSize, int maxStaffSize, int maxSalesmanSize, int maxOrdersSize)
{
    pharmacy_id = next_id++;
    pharmacy_name = name;
    pharmacy_owner == owner;
    max_medication_size = maxMedSize;
    current_medication_size = 0;
    max_staff_size = maxStaffSize;
    current_staff_size = 0;
    max_salesman_size = maxSalesmanSize;
    current_salesman_size = 0;
    max_orders_size = maxOrdersSize;
    current_orders_size = 0;
    total_sales = 0;
    total_purchases = 0;
    total_profit = 0;
    medications = new Medication[max_medication_size];
    medication_quantity = new int[max_medication_size];
    staffs = new Staff[max_staff_size];
    salesmen = new Salesman[max_salesman_size];
    orders = new Order[max_orders_size];
}

Pharmacy::Pharmacy(const Pharmacy &other)
{
    pharmacy_id = next_id++;
    pharmacy_name = other.pharmacy_name;
    pharmacy_owner = other.pharmacy_owner;
    max_medication_size = other.max_medication_size;
    current_medication_size = other.current_medication_size;
    max_staff_size = other.max_staff_size;
    current_staff_size = other.current_staff_size;
    max_salesman_size = other.max_salesman_size;
    current_salesman_size = other.current_salesman_size;
    max_orders_size = other.max_orders_size;
    current_orders_size = other.current_orders_size;
    total_sales = other.total_sales;
    total_purchases = other.total_purchases;
    total_profit = other.total_profit;

    medications = new Medication[max_medication_size];
    medication_quantity = new int[max_medication_size];
    staffs = new Staff[max_staff_size];
    salesmen = new Salesman[max_salesman_size];
    orders = new Order[max_orders_size];

    for (int i = 0; i < current_medication_size; ++i)
    {
        medications[i] = other.medications[i];
        medication_quantity[i] = other.medication_quantity[i];
    }

    for (int i = 0; i < current_staff_size; ++i)
    {
        staffs[i] = other.staffs[i];
    }

    for (int i = 0; i < current_salesman_size; ++i)
    {
        salesmen[i] = other.salesmen[i];
    }

    for (int i = 0; i < current_orders_size; ++i)
    {
        orders[i] = other.orders[i];
    }
}

Pharmacy::~Pharmacy()
{
    delete[] medications;
    delete[] medication_quantity;
    delete[] staffs;
    delete[] salesmen;
    delete[] orders;
}

Pharmacy &Pharmacy::operator=(const Pharmacy &other)
{
    if (this != &other)
    {

        pharmacy_id = next_id++;
        pharmacy_name = other.pharmacy_name;
        pharmacy_owner = other.pharmacy_owner;
        max_medication_size = other.max_medication_size;
        current_medication_size = other.current_medication_size;
        max_staff_size = other.max_staff_size;
        current_staff_size = other.current_staff_size;
        max_salesman_size = other.max_salesman_size;
        current_salesman_size = other.current_salesman_size;
        max_orders_size = other.max_orders_size;
        current_orders_size = other.current_orders_size;
        total_sales = other.total_sales;
        total_purchases = other.total_purchases;
        total_profit = other.total_profit;

        delete[] medications;
        delete[] medication_quantity;
        delete[] staffs;
        delete[] salesmen;
        delete[] orders;
        medications = new Medication[max_medication_size];
        medication_quantity = new int[max_medication_size];
        staffs = new Staff[max_staff_size];
        salesmen = new Salesman[max_salesman_size];
        orders = new Order[max_orders_size];

        for (int i = 0; i < current_medication_size; ++i)
        {
            medications[i] = other.medications[i];
            medication_quantity[i] = other.medication_quantity[i];
        }

        for (int i = 0; i < current_staff_size; ++i)
        {
            staffs[i] = other.staffs[i];
        }

        for (int i = 0; i < current_salesman_size; ++i)
        {
            salesmen[i] = other.salesmen[i];
        }

        for (int i = 0; i < current_orders_size; ++i)
        {
            orders[i] = other.orders[i];
        }
    }
    return *this;
}

void Pharmacy::addMedication(const Medication &medication, int quantity)
{
    if (current_medication_size < max_medication_size)
    {
        medications[current_medication_size] = medication;
        medication_quantity[current_medication_size] = quantity;
        current_medication_size++;
        cout << "Medicine added Successfully." << endl;
    }
    else
    {
        cout << "Error: Cannot add medication, maximum capacity reached." << endl;
    }
}

void Pharmacy::removeMedication(int medicationID)
{
    int index = -1;
    for (int i = 0; i < current_medication_size; ++i)
    {
        if (medications[i].getMedicationID() == medicationID)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        for (int i = index; i < current_medication_size - 1; ++i)
        {
            medications[i] = medications[i + 1];
            medication_quantity[i] = medication_quantity[i + 1];
        }
        current_medication_size--;
    }
    else
    {
        cout << "Error: Medication with ID " << medicationID << " not found." << endl;
    }
}

void Pharmacy::updateMedicationDetails(int medicationID, const Medication &newMedication)
{
    for (int i = 0; i < current_medication_size; ++i)
    {
        if (medications[i].getMedicationID() == medicationID)
        {
            medications[i] = newMedication;
            return;
        }
    }
    cout << "Error: Medication with ID " << medicationID << " not found." << endl;
}

void Pharmacy::addOrder(const Order &order)
{
    if (current_orders_size < max_orders_size)
    {
        orders[current_orders_size] = order;
        current_orders_size++;
    }
    else
    {
        cout << "Error: Cannot add order, maximum capacity reached." << endl;
    }
}

void Pharmacy::addStaff(const Staff &staff)
{
    if (current_staff_size < max_staff_size)
    {
        staffs[current_staff_size] = staff;
        current_staff_size++;
    }
    else
    {
        cout << "Error: Cannot add staff, maximum capacity reached." << endl;
    }
}

void Pharmacy::removeStaff(int staffID)
{
    int index = -1;
    for (int i = 0; i < current_staff_size; ++i)
    {
        if (staffs[i].getStaffID() == staffID)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        for (int i = index; i < current_staff_size - 1; ++i)
        {
            staffs[i] = staffs[i + 1];
        }
        current_staff_size--;
    }
    else
    {
        cout << "Error: Staff with ID " << staffID << " not found." << endl;
    }
}

void Pharmacy::addSalesman(const Salesman &salesman)
{
    if (current_salesman_size < max_salesman_size)
    {
        salesmen[current_salesman_size] = salesman;
        current_salesman_size++;
    }
    else
    {
        cout << "Error: Cannot add salesman, maximum capacity reached." << endl;
    }
}

void Pharmacy::removeSalesman(int salesmanID)
{
    int index = -1;
    for (int i = 0; i < current_salesman_size; ++i)
    {
        if (salesmen[i].getSalesmanID() == salesmanID)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        for (int i = index; i < current_salesman_size - 1; ++i)
        {
            salesmen[i] = salesmen[i + 1];
        }
        current_salesman_size--;
    }
    else
    {
        cout << "Error: Salesman with ID " << salesmanID << " not found." << endl;
    }
}

void Pharmacy::displayOrders() const
{
    cout << "Orders:" << endl;
    for (int i = 0; i < current_orders_size; ++i)
    {
        cout << orders[i] << endl;
    }
}

void Pharmacy::displayStaff() const
{
    cout << "Staff:" << endl;
    for (int i = 0; i < current_staff_size; ++i)
    {
        cout << staffs[i] << endl;
    }
}

void Pharmacy::displaySalesmen() const
{
    cout << "Salesmen:" << endl;
    for (int i = 0; i < current_salesman_size; ++i)
    {
        cout << salesmen[i] << endl;
    }
}

void Pharmacy::displayMedicines() const
{
    cout << "\nMedications:" << endl;
    for (int i = 0; i < current_medication_size; ++i)
    {
        cout << "i+1. " << medications[i] << "\t Quantity: " << medication_quantity[i] << endl;
    }
}
double Pharmacy::getTotalSales() const
{
    return total_sales;
}

void Pharmacy::setTotalSales(double sales)
{
    total_sales = sales;
}

double Pharmacy::getTotalPurchases() const
{
    return total_purchases;
}

void Pharmacy::setTotalPurchases(double purchases)
{
    total_purchases = purchases;
}

double Pharmacy::getTotalProfit() const
{
    return total_profit;
}

void Pharmacy::setTotalProfit(double profit)
{
    total_profit = profit;
}

void Pharmacy::display() const
{
    cout << "Pharmacy Name: " << pharmacy_name << endl;
    cout << "Pharmacy Owner: " << pharmacy_owner << endl;
    cout << "Total Sales: " << total_sales << endl;
    cout << "Total Purchases: " << total_purchases << endl;
    cout << "Total Profit: " << total_profit << endl;
    displayMedicines();
    displayStaff();
    displaySalesmen();
    displayOrders();
}

void Pharmacy::sellMedicine(Pharmacy &customer)
{

    cout << "Available Medicines:" << endl;
    displayMedicines();

    int choice, quantity;
    do
    {
        cout << "Enter the ID of the medicine you want to purchase (0 to finish): ";
        cin >> choice;
        if (choice > 0 && choice <= current_medication_size)
        {
            do
            {
                cout << "Enter Quantity: ";
                cin >> quantity;
            } while (quantity < 0);

            customer.addMedication(medications[choice - 1], quantity);
            cout << "Medicine added to cart." << endl;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

void Pharmacy::purchaseMedicine(const Salesman &salesman)
{

    cout << "Available Medicines from Salesman:" << endl;
    displayMedicines();

    int choice, quantity;
    do
    {
        cout << "Enter the ID of the medicine you want to purchase (0 to finish): ";
        cin >> choice;
        if (choice > 0 && choice <= current_medication_size)
        {
            do
            {
                cout << "Enter Quantity: ";
                cin >> quantity;
            } while (quantity < 0);
            addMedication(medications[choice - 1], quantity);
            cout << "Medicine purchased from salesman." << endl;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

void Pharmacy::showOrdersByCustomer(int id) const
{
    cout << "Orders made by Customer ID " << id << ":" << endl;
    for (int i = 0; i < current_orders_size; ++i)
    {
        if (orders[i].getcustomerId() == id)
        {
            cout << orders[i] << endl;
        }
    }
}

void Pharmacy::showOrdersByMedicine(int id) const
{
    for (int i = 0; i < max_medication_size; i++)
    {

        if (orders[i].getMedicationID(i) == id)
        {
            cout << "\n"
                 << orders[i] << endl;
        }
    }
}

void Pharmacy::showOrdersByDate(Date &date) const
{
    cout << "Orders made on Date: " << date << ":" << endl;
    for (int i = 0; i < current_orders_size; ++i)
    {
        if (orders[i].getOrderDate() == date)
        {
            cout << orders[i] << endl;
        }
    }
}

void Pharmacy::payStaffSalary()
{

    for (int i = 0; i < current_staff_size; ++i)
    {
        total_profit -= staffs[i].getSalary();
    }
}

void Pharmacy::discardExpiryMedicine()
{
    for (int i = 0; i < current_medication_size; ++i)
    {
        if (medications[i].isExpired())
        {
            removeMedication(medications[i].getMedicationID());
        }
    }
}