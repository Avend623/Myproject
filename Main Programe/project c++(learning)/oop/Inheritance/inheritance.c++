#include <iostream>
using namespace std;
class Person
{
private:
    string name;

public:
    void setValue(string n)
    {
        name = n;
    }
    void print()
    {
        cout << "your name is " << name<<endl;
    }
};
class Student : public Person
{
private:
    int grade;

public:
    void setGrade(int g)
    {
        grade = g;
    }
    void display()
    {
        cout << "your grade is " << grade<<endl;
    }
};
int main()
{
    Person ob1;
    ob1.setValue("avend");
    ob1.print();
    Student ob2;                                                                                                                                                                                                                                                                                              
    ob2.setGrade(42);
    ob2.display();
    ob2.setValue("avend");
    ob2.print();
    return 0;
}