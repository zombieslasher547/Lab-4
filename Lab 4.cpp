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

    double total = quantity * unitPrice;

    cout << fixed << setprecision(2);
    cout << "Food: " << foodName << endl;
    cout << "Code: " << itemCode << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Price: $" << unitPrice << endl;
    cout << "Total: $" << total << endl;
    cout << "Member: " << member << endl;

    return 0;
}