// COMSC_210 | Lab 11 | Annie Morales
// IDE used: Visual Studio Code

// Purpose: Bakery Cart Receipt Program
// This program tracks the customers and their orders at my bakery cart, 
// which are then printed out as a receipt. I have a struct to represent a customer. 
// It keeps track their names, order number, items ordered, and the total amount, 
// which are all members in my struct that are populated by user input. Each customer 
// is able to order three items max. Those items are stored a dynamic 
// array within the struct.

#include <iostream>
#include <string>
using namespace std;

// Constants for array sizes
const int OrderSize = 3, NR_Customers = 3; 

// Holds order information
struct Customer
{
    int * orders; // Pointer to dynamically allocate array of orders
    int orderNumber;
    int itemsOrdered;
    string customerName;
    double totalAmount;

    ~Customer() // Destructor: deallocates memory to prevent memory leaks
    {
        if (orders)
            delete[] orders;
        orders = nullptr;
    }
};

// Function prototypes
void inputOrders(Customer *);
void displayOrders(Customer *);

int main() 
{
    Customer *reciept = new Customer[NR_Customers]; // Dynamically allocate array of Customer structs

    inputOrders(reciept); // Gets user input for orders
    displayOrders(reciept); // Displays the orders stored in the array

    delete[] reciept; // Deallocate memory for the array
    reciept = nullptr;
    
    return 0;
}

// Gets user input for orders and stores them in the array
void inputOrders(Customer *orders) 
{
    for (int i = 0; i < OrderSize; i++) 
    {
        cout << endl;
        cout << "Enter order number: #";
        cin >> orders[i].orderNumber;

        cout << "Enter items ordered: ";
        while (true)
        {
            cin >> orders[i].itemsOrdered;
            if (orders[i].itemsOrdered > 0 && orders[i].itemsOrdered <= 3) 
            {
                break; // Valid input, exit the loop
            } else 
            {
                cout << "Invalid input. Please enter a number between 1 and 3." << endl;
            }
        }

        cout << "Enter customer name: ";
        cin.ignore(); // To ignore the newline character left in the buffer
        getline(cin, orders[i].customerName);
        cout << "Enter total amount: $";
        cin >> orders[i].totalAmount;
        cout << endl;
    }
}

// Displays the orders stored in the array
void displayOrders(Customer *orders)
{
    cout << "\nCustomer Orders:\n" << endl;
    for (int i = 0; i < OrderSize; i++) 
    {
        cout << "Order Number: #" << orders[i].orderNumber << endl;
        cout << "Items Ordered: " << orders[i].itemsOrdered << endl;
        cout << "Customer Name: " << orders[i].customerName << endl;
        cout << "Total Amount: $" << orders[i].totalAmount << endl;
        cout << "--------------------------\n";
    }
}