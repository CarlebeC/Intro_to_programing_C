#include <iostream>
using namespace std;
int main (){
    int n;
    do{
        cout << "Enter a positive number: ";
        cin >> n;
        if (n <= 0) {
            cout << "Invalid input, please enter a positive number" << endl;

        }
    } while(n <= 0);
    int count = 0;
    int temp = n;
    while (temp > 0) {
        temp /= 10;
        count++;
    }
    cout << "Number of digits in " << n << " is " << count << endl;

}

