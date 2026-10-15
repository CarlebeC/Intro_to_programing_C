#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main(){
    //Pricing constants
    char package;
    char again;
    int messageUnits;
    const double packageACost = 19.99;
    const double packageBCost = 39.99;
    const double packageCCost = 59.99;
    const double overageRateA = 0.25;
    const double overageRateB = 0.10;
    const int limitA = 20;
    const int limitB = 100;

    cout << fixed << setprecision(2);

do {
    //Package Choice
    while(true) {
        cout << "Which package are you shopping for? (enter A, B, C)? " << endl;
        cin >> package; 
        if (package == 'A' || package == 'a' ||
            package == 'B' || package == 'b' ||
            package == 'C' || package == 'c') {
            break;
        }
        cout << "Invalid package choice. Please enter A, B, or C." << endl;
    }


//Message Units
while (true) {
    cout << "How many message units(1 - 672)? ";
    cin >> messageUnits;

    if (messageUnits >= 1 && messageUnits <= 672) {
        break;
    }
    cout << "Invalid number of units. Must be between 1 and 672." << endl;
}
//Cost Calc for Packages 
double costA = packageACost;
if (messageUnits > limitA) {
    costA += (messageUnits - limitA) * overageRateA;
}

double costB = packageBCost; 
if (messageUnits > limitB) {
    costB += (messageUnits - limitB) * overageRateB;
}

double costC = packageCCost;

//Switchs and Cases Output
double currentCost = 0.0;

switch (package) {
    case 'A':
    case 'a':
        currentCost = costA;
        cout << "The charges are $" << currentCost << "." << endl;
        //Check of other packages offer savings 
        if (costB < currentCost) {
            cout << "By switching to package B you would save $" << (currentCost - costB) << endl;
        }
        if (costC < currentCost) {
            cout << "By switching to package C you would save $" << (currentCost - costC) << endl;
        }
        break;
    case 'B':
    case 'b':
        currentCost = costB;
        cout << "The charges are $" << currentCost << "." << endl;
        if (costB < currentCost) {
            cout << "By switching to package A you would save $" << (currentCost - costA) << endl;
        }
        if (costC < currentCost) {
            cout << "By switching to package C you would save $" << (currentCost - costC) << endl;
        }
        break;
    case 'C':
    case 'c':
        currentCost = costC;
        cout << "The charges are $" << currentCost << "." << endl;
        if (costA < currentCost) {
            cout << "By switching to package A you would save $" << (currentCost - costA) << endl;
        }
        if (costB < currentCost) {
            cout << "By switching to package B you would save $" << (currentCost - costB) << endl;
        }
        break;
    }

cout << endl;

//Run again
cout << "Do you want to go again (y/n)? ";
cin >> again;
cout << endl;

} while (again != 'N' && again != 'n');

cout << "Thank you for using this program. Goodbye." << endl;

return 0;
}
