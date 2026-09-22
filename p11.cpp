#include <iostream>
using namespace std;

int main() {
    int cases_per_day;
    const int bottles_per_case = 12;
    const double profit_per_bottle = 0.22;

    double bottles_per_day;
    double profit_per_day, profit_per_year;

    cout << "Enter number of cases per day: ";
    cin >> cases_per_day;

    bottles_per_day = cases_per_day * bottles_per_case;
    profit_per_day  = bottles_per_day * profit_per_bottle;
    profit_per_year = 365 * profit_per_day;

    cout << "Profit per day: $" << profit_per_day << "\n";
    cout << "Profit per year: $" << profit_per_year << "\n";

    return 0;
}