#include <iostream>
using namespace std;

int main(){
    int n;
    int total = 0;
    
    while(true) {
        cout << "Enter a number (0 to stop): ";
        cin >> n;
        if (n == 0){
            break;
        }
        if (n < 0){
            continue;
        }
        else 
        total += n;
    }
    cout << "Total of positive numbers = " << total << endl;
}