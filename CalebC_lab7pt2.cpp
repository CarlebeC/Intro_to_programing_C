#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class CoffeeOrder {
private:
    string drinkName;
    string size;
    double basePrice;
    int extraShots;
    static int orderCount;

public:
    // Default constructor
    CoffeeOrder() {
        drinkName = "House Coffee";
        size = "Small";
        basePrice = 2.00;
        extraShots = 0;
        orderCount++;
    }

    // Parameterized constructor
    CoffeeOrder(string drinkName, string size, double basePrice, int extraShots) {
        this->drinkName = drinkName;
        this->size = size;
        this->basePrice = basePrice;
        this->extraShots = extraShots;
        orderCount++;
    }

    static int getOrderCount() {
        return orderCount;
    }

    double getTotalPrice() {
        return basePrice + extraShots * 0.75;
    }

    void printReceipt() {
        cout << "Drink: " << drinkName << " (" << size << ")" << endl;
        cout << "Extra shots: " << extraShots << endl;
        cout << fixed << setprecision(2);
        cout << "Total: $" << getTotalPrice() << endl << endl;
    }
};

// Static members must be defined outside the class
int CoffeeOrder::orderCount = 0;

int main() {
    CoffeeOrder order1;
    CoffeeOrder order2("Caramel Latte", "Large", 5.25, 1);
    CoffeeOrder order3("Mocha", "Medium", 5.00, 2);

    order1.printReceipt();
    order2.printReceipt();
    order3.printReceipt();

    cout << "Total orders created: " << CoffeeOrder::getOrderCount() << endl;
    return 0;
}