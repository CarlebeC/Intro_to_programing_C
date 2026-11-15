#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct RentalCar
{
    string brand;
    int year;
    double dailyRate;
};

int main()
{
    RentalCar car1, car2;
    int days;

    cout << "----- Car Rental Comparison -----" << endl;

    
    cout << "\nEnter details for Car 1:" << endl;
    cout << "Brand: ";
    getline(cin, car1.brand);
    cout << "Year: ";
    cin >> car1.year;
    cout << "Daily rental rate: ";
    cin >> car1.dailyRate;

   
    cin.ignore();

    
    cout << "\nEnter details for Car 2:" << endl;
    cout << "Brand: ";
    getline(cin, car2.brand);
    cout << "Year: ";
    cin >> car2.year;
    cout << "Daily rental rate: ";
    cin >> car2.dailyRate;

    cout << "\nEnter number of rental days: ";
    cin >> days;


    double total1 = car1.dailyRate * days;
    double total2 = car2.dailyRate * days;

    // Set once; it stays in effect for every number printed below
    cout << fixed << setprecision(2);

    cout << "\n----- Rental Summary -----" << endl;

    cout << "\nCar 1: " << car1.brand << " (" << car1.year << ")" << endl;
    cout << "Daily Rate: $" << car1.dailyRate << endl;
    cout << "Total Cost: $" << total1 << endl;

    cout << "\nCar 2: " << car2.brand << " (" << car2.year << ")" << endl;
    cout << "Daily Rate: $" << car2.dailyRate << endl;
    cout << "Total Cost: $" << total2 << endl;

    cout << "\n----- Recommendation -----" << endl;

    if (total1 < total2)
    {
        cout << car1.brand << " is the cheaper rental option." << endl;
        cout << "You save: $" << total2 - total1 << endl;
    }
    else if (total2 < total1)
    {
        cout << car2.brand << " is the cheaper rental option." << endl;
        cout << "You save: $" << total1 - total2 << endl;
    }
    else
    {
        cout << "Both cars cost the same." << endl;
    }

    return 0;
}