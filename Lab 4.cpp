
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

    // 6. Subtotal and Discount Calculations
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

    if (!isMember && subtotal >= 50.0) {
        cout << "Notice: Orders of $50 or more qualify for higher savings with membership.\n";
    }

    double taxableSubtotal = subtotal - discount;

    // 7. Individual Tax Calculations
    const double AR_STATE_TAX_RATE = 0.065;
    const double FAULKNER_TAX_RATE = 0.005;
    const double CONWAY_TAX_RATE = 0.02125;

    double arStateTax = taxableSubtotal * AR_STATE_TAX_RATE;
    double faulknerTax = taxableSubtotal * FAULKNER_TAX_RATE;
    double conwayTax = taxableSubtotal * CONWAY_TAX_RATE;
    double totalTax = arStateTax + faulknerTax + conwayTax;

    // 8. Tax Breakdown Table Output
    cout << "\n--- Tax Breakdown ---\n";
    cout << left << setw(26) << "Tax Name"
        << setw(12) << "Rate"
        << right << setw(10) << "Amount" << endl;
    cout << string(48, '-') << endl;

    cout << left << setw(26) << "Arkansas State Tax"
        << setw(12) << "6.500%"
        << right << setw(9) << "$" << arStateTax << endl;

    cout << left << setw(26) << "Faulkner County Tax"
        << setw(12) << "0.500%"
        << right << setw(9) << "$" << faulknerTax << endl;

    cout << left << setw(26) << "Conway Municipal Tax"
        << setw(12) << "2.125%"
        << right << setw(9) << "$" << conwayTax << endl;

    cout << string(48, '-') << endl;
    cout << left << setw(38) << "Total Tax"
        << right << setw(9) << "$" << totalTax << endl;

    // 9. Tip Menu Display and Calculation
    double tip15 = taxableSubtotal * 0.15;
    double tip20 = taxableSubtotal * 0.20;
    double tip25 = taxableSubtotal * 0.25;

    cout << "\nTip Selection\t\tAmount\n";
    cout << "A. 15%\t\t\t$" << tip15 << "\n";
    cout << "B. 20%\t\t\t$" << tip20 << "\n";
    cout << "C. 25%\t\t\t$" << tip25 << "\n";
    cout << "D. Other Amount\n\n";

    char tipOption;
    double tipAmount = 0.0;

    cout << "What tip do you choose? ";
    cin >> tipOption;

    switch (tipOption) {
    case 'A':
    case 'a':
        tipAmount = tip15;
        break;
    case 'B':
    case 'b':
        tipAmount = tip20;
        break;
    case 'C':
    case 'c':
        tipAmount = tip25;
        break;
    case 'D':
    case 'd':
        cout << "How much would you like to tip? $";
        cin >> tipAmount;
        break;
    default:
        tipAmount = 0.0;
        break;
    }

    if (tipAmount < 0.0) {
        tipAmount = 0.0;
    }

    // 10. Grand Total Calculation
    double total = taxableSubtotal + totalTax + tipAmount;

    // 11. Final Receipt Output
    cout << "\n================ Receipt ================\n";
    cout << "Food: " << foodName << " (" << sizeName << ")\n";
    cout << "Quantity: " << quantity << endl;
    cout << "Unit Price: $" << unitPrice << endl;
    cout << "Subtotal: $" << subtotal << endl;
    cout << "Status: " << memberStatus << endl;
    cout << "Discount: -$" << discount << endl;
    cout << "Tax: $" << totalTax << endl;
    cout << "Tip: $" << tipAmount << endl;
    cout << "Total: $" << total << endl;
    cout << "Notes: " << cashierNotes << endl;
    cout << "=========================================\n";

    // 12. Inventory Audit Table
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
    