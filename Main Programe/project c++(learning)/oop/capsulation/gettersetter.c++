#include <iostream>
using namespace std;
class Company
{
private:
    int salary;
    string name;

public:
    void setvalue();
    void print();
    void getname();
    int getvalue();
};
void Company::setvalue()
{
    cout << "enter your name:";
    cin >> name;
    cout << "enter your salary:";
    cin >> salary;
}
void Company::print()
{
    cout << "your name is " << name << endl;
    cout << "your sal is " << salary << endl;
}
void Company::getname()
{
    cout << "your name is " << name << endl;
}
int Company::getvalue()
{
    return salary;
}
int main()
{
    Company ob1;
    Company ob2;
    ob1.setvalue();
    ob2.setvalue();
    ob1.print();
    ob2.print();
    cout << "Total salary:" << ob2.getvalue() + ob1.getvalue();
    return 0;
}