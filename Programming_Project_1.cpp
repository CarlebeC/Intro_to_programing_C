#include <cmath>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Read a whole line so entries such as "2abc" are rejected.
template <typename T>
bool readNumber(const string& prompt, T& value) {
    string line;
    while (true) {
        cout << prompt;
        if (!getline(cin, line)) return false;
        istringstream input(line);
        char extra;
        if ((input >> value) && !(input >> extra)) return true;
        cout << "Invalid input. Please enter a number only." << endl;
    }
}

// Accept yes/no answers without ending the program on an invalid entry.
bool readYesNo(const string& prompt, bool& answer) {
    string line;
    while (true) {
        cout << prompt;
        if (!getline(cin, line)) return false;
        istringstream input(line);
        string word;
        char extra;
        if ((input >> word) && !(input >> extra)) {
            for (char& letter : word) {
                letter = static_cast<char>(tolower(static_cast<unsigned char>(letter)));
            }
            if (word == "yes" || word == "y") {
                answer = true;
                return true;
            }
            if (word == "no" || word == "n") {
                answer = false;
                return true;
            }
        }
        cout << "Invalid answer. Please enter y/n or yes/no." << endl;
    }
}

int main() {
    // Fixed example rates: units of foreign currency per 1 USD.
    const double EURO = 0.93;
    const double AUD = 1.55;
    const double YEN = 145.60;
    const double INR = 82.56;
    const double GBP = 0.77; // Example rate; update before real use.

    while (true) {
        cout << "Currency Converter - Convert US dollars to:" << endl;
        cout << "1. Euro" << endl;
        cout << "2. Australian Dollar" << endl;
        cout << "3. Japanese Yen" << endl;
        cout << "4. Indian Rupee" << endl;
        cout << "5. British Pound" << endl;
        cout << "6. Quit program" << endl;
        cout << "Uses fixed example exchange rates." << endl;

        int choice;
        while (true) {
            if (!readNumber("Enter your choice (1-6): ", choice)) return 0;
            if (choice >= 1 && choice <= 6) break;
            cout << "Invalid choice. Please choose a number from 1 to 6." << endl;
        }
        if (choice == 6) {
            cout << "Goodbye!" << endl;
            return 0;
        }

        const double rates[] = {EURO, AUD, YEN, INR, GBP};
        const string currencies[] = {"Euros", "Australian Dollars", "Japanese Yen",
                                     "Indian Rupees", "British Pounds"};
        double rate = rates[choice - 1];
        string currency = currencies[choice - 1];

        cout << "Do you know how much USD you want to convert?" << endl;
        cout << "1. Yes - enter an amount in USD" << endl;
        cout << "2. Not sure - enter how much I want in " << currency << endl;
        int mode;
        while (true) {
            if (!readNumber("Choose 1 or 2: ", mode)) return 0;
            if (mode == 1) break;
            if (mode == 2) {
                bool confirmed;
                if (!readYesNo("You chose to enter an amount in " + currency + " and calculate its USD equivalent (the USD needed to receive it). Is that what you want? (y/n or yes/no): ", confirmed)) return 0;
                if (confirmed) break;
                cout << "Please choose your conversion option again." << endl;
                continue;
            }
            cout << "Invalid choice. Please choose 1 or 2." << endl;
        }

        double amount;
        string prompt = mode == 1 ? "Enter your amount in USD: "
                                  : "Enter how much you want in " + currency + ": ";
        while (true) {
            if (!readNumber(prompt, amount)) return 0;
            if (isfinite(amount) && amount >= 0 &&
                isfinite(mode == 1 ? amount * rate : amount / rate)) break;
            cout << "Invalid amount. Enter a finite, non-negative amount within range." << endl;
        }

        cout << fixed << setprecision(2);
        if (mode == 1) {
            cout << "$" << amount << " USD would be " << amount * rate
                 << " " << currency << "." << endl;
        } else {
            cout << "To receive " << amount << " " << currency
                 << ", you need to convert $" << amount / rate << " USD." << endl;
        }
        bool again;
        if (!readYesNo("Would you like to convert again? (y/n or yes/no): ", again)) return 0;
        if (!again) {
            cout << "Goodbye!" << endl;
            break;
        }
        cout << endl;
    }
    return 0;
}
