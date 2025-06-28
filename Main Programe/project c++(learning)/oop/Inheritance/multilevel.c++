/* Single inheritance
 class A {};
 class B : public A {};*/

/* Multiple inheritance
class A {};
class B : public A {};
class C : public A , public B */
#include<iostream>
using namespace std;
class Person
{
    private:
        string name;
        int age;
    public:
        Person(string n,int a)
        {
            age = a;
            name = n;
        }
        void print()
        {
            cout<<"your name is "<<name<<endl;
            cout<<"your age is "<<age<<endl;
        }
};
class Employee : public Person
{
    private:
        int id;
        int salary;
    public:
        Employee(string n,int a,int i,int s):Person(n,a)
        {
            id = i;
            salary = s;
        }
        void print()
        {
            cout<<"your id is "<<id<<endl;
            cout<<"your salary is "<<salary<<endl;
        }
};
class Student : public Employee
{
    private:
        string email;
    public:
        Student(string n,int a,int i,int s,string e):Employee(n,a,i,s)
        {
            email = e;
        }
        void print()
        {
            Person::print();
            Employee::print();
            cout<<"your email is "<<email<<endl;
        }
};
int main()
{
    Student ob1("ahmed",22,141551,10111,"ahmed@gmail.com");
    ob1.print();
    return 0;
}

