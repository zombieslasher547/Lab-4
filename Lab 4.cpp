#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    char menuOption;
    char sizeChoice;
    string foodName = "";
    string sizeName = "";
    double unitPrice = 0.0;
    bool validSelection = true;

    int quantity;
    char member;
    string cashierNotes;

    // Sets fixed-point notation to display two decimal places for currency
    cout << fixed << setprecision(2);

    // 1. Menu Display
    cout << "Drink\t\t\tSmall (s)\tMedium (m)\tLarge (l)\n";
    cout << "A. Apple Juice\t\t2.50\t\t3.50\t\t4.50\n";
    cout << "B. Beer\t\t\t5.00\t\t7.00\t\t9.00\n";
    cout << "C. Coffee\t\t1.75\t\t2.25\t\t2.75\n";
    cout << "D. Soda\t\t\t1.50\t\t2.00\t\t2.50\n\n";

    // 2. User Selections
    cout << "Select an option (A, B, C, D): ";
    cin >> menuOption;

    cout << "Select a size (s, m, l): ";
    cin >> sizeChoice;

    // 3. Determine Food Name and Unit Price
    switch (menuOption) {
    case 'A':
    case 'a':
        foodName = "Apple Juice";
        if (sizeChoice == 's' || sizeChoice == 'S') {
            sizeName = "Small";
            unitPrice = 2.50;
        }
        else if (sizeChoice == 'm' || sizeChoice == 'M') {
            sizeName = "Medium";
            unitPrice = 3.50;
        }
        else if (sizeChoice == 'l' || sizeChoice == 'L') {
            sizeName = "Large";
            unitPrice = 4.50;
        }
        else {
            validSelection = false;
        }
        break;

    case 'B':
    case 'b':
        foodName = "Beer";
        if (sizeChoice == 's' || sizeChoice == 'S') {
            sizeName = "Small";
            unitPrice = 5.00;
        }
        else if (sizeChoice == 'm' || sizeChoice == 'M') {
            sizeName = "Medium";
            unitPrice = 7.00;
        }
        else if (sizeChoice == 'l' || sizeChoice == 'L') {
            sizeName = "Large";
            unitPrice = 9.00;
        }
        else {
            validSelection = false;
        }
        break;

    case 'C':
    case 'c':
        foodName = "Coffee";
        if (sizeChoice == 's' || sizeChoice == 'S') {
            sizeName = "Small";
            unitPrice = 1.75;
        }
        else if (sizeChoice == 'm' || sizeChoice == 'M') {
            sizeName = "Medium";
            unitPrice = 2.25;
        }
        else if (sizeChoice == 'l' || sizeChoice == 'L') {
            sizeName = "Large";
            unitPrice = 2.75;
        }
        else {
            validSelection = false;
        }
        break;

    case 'D':
    case 'd':
        foodName = "Soda";
        if (sizeChoice == 's' || sizeChoice == 'S') {
            sizeName = "Small";
            unitPrice = 1.50;
        }
        else if (sizeChoice == 'm' || sizeChoice == 'M') {
            sizeName = "Medium";
            unitPrice = 2.00;
        }
        else if (sizeChoice == 'l' || sizeChoice == 'L') {
            sizeName = "Large";
            unitPrice = 2.50;
        }
        else {
            validSelection = false;
        }
        break;

    default:
        validSelection = false;
        break;
    }

    if (!validSelection) {
        cout << "Invalid menu option or size selected.\n";
        return 1;
    }

    // 4. Order Confirmation Output
    cout << "\nOrder: " << foodName << " (" << sizeName << ") - $" << unitPrice << endl;

    // 5. Quantity, Membership, and Notes Input
    cout << "\nEnter quantity: ";
    cin >> quantity;

    cout << "Member (y/n): ";
    cin >> member;

    // Clears the trailing newline character from the stream buffer before getline
    cin.ignore();

    cout << "Enter cashier notes: ";
    getline(cin, cashierNotes);

    // 6. Subtotal, Discount, and Tax Calculations
    double subtotal = quantity * unitPrice;
    double discount = 0.0;
    string memberStatus;
    bool isMember = (member == 'y' || member == 'Y');

    if (isMember) {
        memberStatus = "Member";
        discount = subtotal * 0.10;
    }
    else {
        memberStatus = "Not Member";
        discount = 0.0;
    }

    if (!isMember && quantity >= 10) {
        cout << "Notice: Member discount would apply to bulk purchases.\n";
    }

    double discountedSubtotal = subtotal - discount;
    double taxRate = 0.07;
    double tax = discountedSubtotal * taxRate;
    double total = discountedSubtotal + tax;

    // 7. Receipt Output
    cout << "\nReceipt\n";
    cout << "Food: " << foodName << " (" << sizeName << ")\n";
    cout << "Quantity: " << quantity << endl;
    cout << "Unit Price: $" << unitPrice << endl;
    cout << "Subtotal: $" << subtotal << endl;
    cout << "Status: " << memberStatus << endl;
    cout << "Discount: -$" << discount << endl;
    cout << "Tax: $" << tax << endl;
    cout << "Total: $" << total << endl;
    cout << "Notes: " << cashierNotes << endl;

    // 8. Inventory Audit Table
    cout << "\nInventory Audit\n";
    cout << left << setw(16) << "Item"
        << right << setw(6) << "Qty"
        << right << setw(10) << "Price"
        << right << setw(10) << "Total" << endl;

    cout << left << setw(16) << foodName
        << right << setw(6) << quantity
        << right << setw(10) << unitPrice
        << right << setw(10) << subtotal << endl;

    return 0;
}