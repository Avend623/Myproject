#include <iostream>
using namespace std;
int main()
{
    int age = 20;
    string name = "ahmed";
    char grade = 'B';
    float gpa = 2.3;
    bool success = false;

    cout << "your name is " << name << endl
         << "age is " << age + 1<< endl
         << "your gpa is "<<gpa<<endl;//# THE END
    if (success == true)//! THIS -IF- IS NOT IN VIDEO
    {
        cout << "you are success";
    };
    if (success == false)
    {
        cout << "your are failed";
    };
    return 0;
}