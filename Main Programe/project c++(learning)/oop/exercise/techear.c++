#include <iostream>
using namespace std;
class Engineer;
class Teacher
{
private:
    int salary;
    string name;

public:
    Teacher()
    {
        cout << "enter your name:";
        cin >> name;
        cout << "enter your salary:";
        cin >> salary;
    }
    friend void add(Teacher ob1, Engineer ob2);
};
class Engineer
{
private:
    int salary;
    string name;

public:
    Engineer()
    {
        cout << "enter your name:";
        cin >> name;
        cout << "enter your salary:";
        cin >> salary;
    }
    friend void add(Teacher ob1, Engineer ob2);
};
void add(Teacher ob1, Engineer ob2)
{
    if(ob1.name == "ahmed")
    {
        cout << "the new salary of Teacher " << ob1.name << endl;
        ob1.salary += 1000;
        cout << ob1.salary << endl;
    }
    if(ob2.name == "ali")
    {
        cout << "the new salary of Engineer " << ob1.name << endl;
        ob2.salary += 1000;
        cout << ob2.salary << endl;
    }}
int main()
{
    Teacher ob1;
    Engineer ob2;
    add(ob1, ob2);
    return 0;
}