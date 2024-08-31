#include <iostream>
using namespace std;
class Person
{
private:
    string name;
    int age;
    string email;

public:
    void setValue(string n, int a, string e)
    {
        name = n;
        age = a;
        email = e;
    }
    void print()
    {
        cout << name << endl;
        cout << age << endl;
        cout << email << endl;
    }
};
class Student
{
    private:
        int grade;
    public:
        void setgrade(int g)
        {
            grade = g;
        }
        void print()
        {
            cout<<"grade is "<<grade<<endl;
        }
};
int main()
{
    Person ob1;
    ob1.setValue("avend",20,"avend2@gmail");
    ob1.print();
    Student ob2;
    ob2.setgrade(10);
    ob2.print();



    return 0;
}