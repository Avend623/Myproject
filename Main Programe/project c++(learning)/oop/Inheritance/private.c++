#include<iostream>
using namespace std;
class First
{
    private:
        int x;
    public:
        void print()
        {
            cout<<x<<endl;
        }
        void setValue(int a)
        {
            x = a;
        }
};
class Second : private First
{
    public:
    void hello()
    {
        setValue(5);
        print();
    }
};
int main()
{
    Second ob1;
    ob1.hello();
}