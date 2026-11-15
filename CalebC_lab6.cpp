#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Student
{
    string name;
    int studentID;
    double exam1;
    double exam2;
    double exam3;

    void printstudentInfo()
    {
        cout << "Student Name: " << name << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Exam 1 Score: " << exam1 << endl;
        cout << "Exam 2 Score: " << exam2 << endl;
        cout << "Exam 3 Score: " << exam3 << endl;
    }
};

int main() {
    Student student1;
    cout <<" Enter student name: ";
    getline(cin, student1.name);

    cout << "Enter student ID: ";
    cin >> student1.studentID;

    cout << "Enter Exam 1 score: ";
    cin >> student1.exam1;

    cout << "Enter Exam 2 score: ";
    cin >> student1.exam2;

    cout << "Enter Exam 3 score: ";
    cin >> student1.exam3;

    double average = (student1.exam1 + student1.exam2 + student1.exam3) / 3.0;

    cout << "\n----- Student Grade Report -----" << endl;
    cout << "Name: " << student1.studentID << endl; 
    cout << "Student ID: " << student1.studentID << endl;
    cout << "Exam 1: " << student1.exam1 << endl;
    cout << "Exam 2: " << student1.exam2 << endl;
    cout << "Exam 3: " << student1.exam3 << endl;
    cout << "Average Score: " << fixed << setprecision(2) << average << endl;
    
    return 0;
    
    
}
