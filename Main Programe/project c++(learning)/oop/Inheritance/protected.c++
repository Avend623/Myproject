#include<iostream>
using namespace std;
class First
{
    private:
        int x = 10;
    public:
        int y = 5;
    protected:
        int z = 1;
    public:
        void print()
        {
            cout<<z<<endl;
        }
};
class Second : public First
{
    public:
        void display()
        {
            cout<<"z is proctected and equal "<<z<<endl;
        }
};

int main()
{
    First ob1;
    Second ob2;
    ob2.display();
    ob1.y = 10;
    //! ob1.x = 20;
    //! ob1.z = 50;
    return 0;
}