// COMSC_210 | Lab 11 | Annie Morales
// IDE used: Visual Studio Code

#include <iostream>
#include <string>
using namespace std;

const int OrderSize = 3; 

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
        // Placeholder for code.
    }
};

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

int main() 
{


    return 0;
}