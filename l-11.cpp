// COMSC_210 | Lab 11 | Annie Morales
// IDE used: Visual Studio Code

#include <iostream>
#include <string>
using namespace std;

const int OrderSize = 3, NR_Customers = 5; 

// Holds order information
struct Customer
{
    int * orders;
    int orderNumber;
    int itemsOrdered;
    string customerName;
    double totalAmount;

    ~Customer() // Destructor 
    {
        if (orders)
            delete[] orders;
        orders = nullptr;
    }
};

void inputOrders(Customer *);
void displayOrders(Customer *);

int main() 
{


    return 0;
}

void inputOrders(Customer *orders) 
{
    for (int i = 0; i < OrderSize; i++) 
    {
        cout << "Enter order number: ";
        cin >> orders[i].orderNumber;
        cout << "Enter items ordered: ";
        cin >> orders[i].itemsOrdered;
        cout << "Enter customer name: ";
        cin.ignore(); // To ignore the newline character left in the buffer
        getline(cin, orders[i].customerName);
        cout << "Enter total amount: ";
        cin >> orders[i].totalAmount;
    }
}

void displayOrders(Customer *orders)
{
    cout << "\nCustomer Orders:\n";
    for (int i = 0; i < OrderSize; i++) 
    {
        cout << "Order Number: " << orders[i].orderNumber << endl;
        cout << "Items Ordered: " << orders[i].itemsOrdered << endl;
        cout << "Customer Name: " << orders[i].customerName << endl;
        cout << "Total Amount: $" << orders[i].totalAmount << endl;
        cout << "--------------------------\n";
    }
}