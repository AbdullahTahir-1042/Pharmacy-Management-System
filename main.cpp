#include <iostream>
#include "Pharmacy.h"
#include <string>
using namespace std;

void addPharmacy(Pharmacy *pharmacies[], int &numPharmacies)
{
    if (numPharmacies < 10) // Check limit
    {
        pharmacies[numPharmacies++] = new Pharmacy();
        cout << "Pharmacy added successfully." << endl;
    }
    else
    {
        cout << "Maximum number of pharmacies reached!" << endl;
    }
}

void displayMenu()
{
    cout << "\nPharmacy Menu" << endl;
    cout << "0. Add Pharmacy" << endl;
    cout << "1. Add Medication" << endl;
    cout << "2. Remove Medication" << endl;
    cout << "3. Add Staff" << endl;
    cout << "4. Remove Staff" << endl;
    cout << "5. Add Salesman" << endl;
    cout << "6. Remove Salesman" << endl;
    cout << "7. Sell Medicine" << endl;
    cout << "8. Purchase Medicine" << endl;
    cout << "9. Show Orders by Customer" << endl;
    cout << "10. Show Orders by Medicine" << endl;
    cout << "11. Show Orders by Date" << endl;
    cout << "12. Pay Staff Salary" << endl;
    cout << "13. Discard Expired Medicine" << endl;
    cout << "14. Display Pharmacy Details" << endl;
    cout << "15. Exit" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    const int MAX_PHARMACIES = 10;
    Pharmacy *pharmacies[MAX_PHARMACIES];
    int numPharmacies = 0;
    Staff s;
    Medication m;
    Salesman sale;
    Date date;
    int choice;

    do
    {
        displayMenu();
        cin >> choice;

        if (choice == 0)
        {
            addPharmacy(pharmacies, numPharmacies);
            continue; // Skip asking for pharmacy index
        }

        if (choice == 15)
        {
            cout << "Exiting." << endl;
            break;
        }

        int pharmacyIndex;
        cout << "Enter the index of the pharmacy: ";
        cin >> pharmacyIndex;

        if (pharmacyIndex >= 0 && pharmacyIndex < numPharmacies)
        {
            switch (choice)
            {
            case 1:
            {
                int quantity;
                cout << "Enter Medication: ";
                cin >> m;
                cout << "Enter quantity: ";
                cin >> quantity;
                pharmacies[pharmacyIndex]->addMedication(m, quantity);
                break;
            }
            case 2:
            {
                int id;
                cout << "Enter Medication Id: ";
                cin >> id;
                pharmacies[pharmacyIndex]->removeMedication(id);
                break;
            }
            case 3:
                cout << "Enter Staff details: ";
                cin >> s;
                pharmacies[pharmacyIndex]->addStaff(s);
                break;
            case 4:
            {
                int id;
                cout << "Enter Staff ID: ";
                cin >> id;
                pharmacies[pharmacyIndex]->removeStaff(id);
                break;
            }
            case 5:
                cout << "Enter Salesman Details: ";
                cin >> sale;
                pharmacies[pharmacyIndex]->addSalesman(sale);
                break;
            case 6:
            {
                int id;
                cout << "Enter Salesman ID: ";
                cin >> id;
                pharmacies[pharmacyIndex]->removeSalesman(id);
                break;
            }
            case 7:
                cout << "Sell Medicine functionality not implemented yet." << endl;
                break;
            case 8:
                cout << "Purchase Medicine functionality not implemented yet." << endl;
                break;
            case 9:
            {
                int id;
                cout << "Enter Customer ID: ";
                cin >> id;
                pharmacies[pharmacyIndex]->showOrdersByCustomer(id);
                break;
            }
            case 10:
            {
                int id;
                cout << "Enter Medicine ID: ";
                cin >> id;
                pharmacies[pharmacyIndex]->showOrdersByMedicine(id);
                break;
            }
            case 11:
                cout << "Enter Purchase Date: ";
                cin >> date;
                pharmacies[pharmacyIndex]->showOrdersByDate(date);
                break;
            case 12:
                pharmacies[pharmacyIndex]->payStaffSalary();
                cout << "Staff salary paid." << endl;
                break;
            case 13:
                pharmacies[pharmacyIndex]->discardExpiryMedicine();
                cout << "Expired medicines discarded." << endl;
                break;
            case 14:
                pharmacies[pharmacyIndex]->display();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
        else
        {
            cout << "Invalid pharmacy index." << endl;
        }
    } while (true);

    for (int i = 0; i < numPharmacies; ++i)
    {
        delete pharmacies[i];
    }

    return 0;
}
