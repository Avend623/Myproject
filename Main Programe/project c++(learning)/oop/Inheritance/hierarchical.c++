/* Single inheritance
 class A {};
 class B : public A {};*/

/* Multiple inheritance
class A {};
class B : public A {};
class C : public A , public B */
#include <iostream>
using namespace std;
class Person
{
private:
    string name;
    int age;

public:
    Person(string n, int a)
    {
        name = n;
        age = a;
    }
    void print()
    {
        cout << "your name is " << name << endl;
        cout << "your age is " << age << endl;
    }
};
class Student : public Person
{
private:
    int grade;

public:
    Student(string n, int a, int g) : Person(n, a)
    {
        grade = g;
    }
    void print()
    {
        cout << "your grade is " << grade << endl;
    }
};
class Employee : public Person
{
private:
    int id;
    int salary;

public:
    Employee(string n, int a, int i, int s) : Person(n, a)
    {
        id = i;
        salary = s;
    }
    void print()
    {
        Person::print();
        cout<<"your id is "<<id<<endl;
        cout<<"your salary is "<<salary<<endl;
    }
};
int main()
{
    // Person ob1("Avend",15);
    // ob1.print();
    // Student ob2("Ali",20,78);
    // ob2.print();
    Employee ob3("Ahmed",26,154331,5000);
    ob3.print();
    return 0;
}