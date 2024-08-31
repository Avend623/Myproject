#include <iostream>
using namespace std;
class A
{
public:
    void print()
    {
        cout << "function from class A" << endl;
}
}
;
class B : public A
{
public:
    void print()
    {
        A::print();
        cout << "function from class B" << endl;
    }
};
int main()
{
    B ob1;
    ob1.print();

    return 0;
}