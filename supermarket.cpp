#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //declare variables
    int numItems = 0;
    double total = 0.0;

    //number of items
    cout << "Enter number of grocery items you will be entering: ";
    cin >> numItems;
    cout << "\n";

    //input message
    cout << "Please enter the item names as one word only. Example: tomatoes\n" ;
    cout << "Enter the cost as a decimal number. Example: 2.44\n\n";

    //declare dynamic arrays
    string* itemName = new string[numItems];
    double* itemCost = new double[numItems];

    //item name and price input
    for (int i = 0; i < numItems; ++i)
    {
        cout << "Enter item " << i + 1 << ": ";
        cin >> itemName[i];
        cout << "Enter the cost of the " << itemName[i] << " $";
        cin >> itemCost[i];
        cout << "\n";
    }

    //Display Data
    cout << "Items    Cost\n";
    for (int i = 0; i < numItems; ++i)
    {
        cout << setw(10) << left << itemName[i] << "$" << setw(6) << fixed << setprecision(2) << itemCost[i] << endl;
        total += itemCost[i];
    }

    //total calculations
    cout << "Total: $" << fixed << setprecision(2) << total << endl;

    //delete dynamic arrays
    delete[] itemName;
    delete[] itemCost;

    return 0;
}
