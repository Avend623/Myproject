#include <iostream>
using namespace std;
class A
{
private:
    string name;
    int age;

public:
    A(string n, int a)
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
class B
{
    private:
        string email;
    public:
        B(string e)
    {
        email = e;
    }
    void print()
    {
        cout << "your email is " << email << endl;
    }
};
class C : public A , public B
{
    private:
        int gradeFinal;
    public:
        C(string n,string e,int a,int g) : A(n,a),B(e)
        {
            gradeFinal = g;
        }
        void print()
        {
            cout<<"your GF is "<<gradeFinal;
        } 
        void printA()
        {
            A::print();
            B::print();
            print();
        }   
};
int main()
{
    // A ob1("Avend",15);
    // ob1.print();
    // B ob2("avend@gmail");
    // ob2.print();
    C ob3("Avend","avend@gmail",15,100);
    ob3.printA();
    return 0;
}