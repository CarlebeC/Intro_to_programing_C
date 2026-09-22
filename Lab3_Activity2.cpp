#include <iostream>
using namespace std;
int main() {
    int score;
    int A = 90;
    int B = 80;
    int C = 70;
    int D = 60;
    int F = 0;
    cout << "Enter your score: ";
    cin >> score;
    if (score >= 90) {
        cout << "Your grade is A." << endl;
    }
    else if (score >= 80 && score < 90) {
        cout << "Your grade is B." << endl;
    }
    else if (score >= 70 && score < 80) {
        cout << "Your grade is C." << endl;
    }
    else if (score >= 60 && score < 70) {
        cout << "Your grade is D." << endl;
    }
    else {
        cout << "Your grade is F." << endl;
    }
}
