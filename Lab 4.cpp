
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string foodName;
    char itemCode;
    int quantity;
    double unitPrice;
    char member;
    string cashierNotes;

    // 1. User Input
    cout << "Enter food name: ";
    getline(cin, foodName);

    cout << "Enter item code: ";
    cin >> itemCode;

    cout << "Enter quantity: ";
    cin >> quantity;

    cout << "Enter unit price: ";
    cin >> unitPrice;

    cout << "Member (y/n): ";
    cin >> member;

    // Clear newline character so getline() does not skip
    cin.ignore();

    cout << "Enter cashier notes: ";
    getline(cin, cashierNotes);

    // 2. Calculations
    double subtotal = quantity * unitPrice;
    double discount = 0.0;
    string memberStatus;

    if (member == 'y' || member == 'Y') {
        memberStatus = "Member";
        discount = subtotal * 0.10; // 10% member discount
    }
    else {
        memberStatus = "Not Member";
        discount = 0.0;
    }

    double discountedSubtotal = subtotal - discount;
    double taxRate = 0.07; // 7% sales tax
    double tax = discountedSubtotal * taxRate;
    double total = discountedSubtotal + tax;

    // 3. Receipt Output
    cout << fixed << setprecision(2);

    cout << "\nReceipt\n";
    cout << "Food: " << foodName << endl;
    cout << "Code: " << itemCode << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Unit Price: $" << unitPrice << endl;
    cout << "Subtotal: $" << subtotal << endl;
    cout << "Status: " << memberStatus << endl;
    cout << "Discount: -$" << discount << endl;
    cout << "Tax: $" << tax << endl;
    cout << "Total: $" << total << endl;
    cout << "Notes: " << cashierNotes << endl;

    // 4. Inventory Audit Table
    cout << "\nInventory Audit\n";
    cout << left << setw(6) << "Code"
        << left << setw(16) << "Item"
        << right << setw(6) << "Qty"
        << right << setw(10) << "Price"
        << right << setw(10) << "Total" << endl;

    cout << left << setw(6) << itemCode
        << left << setw(16) << foodName
        << right << setw(6) << quantity
        << right << setw(10) << unitPrice
        << right << setw(10) << subtotal << endl;

    return 0;
}
