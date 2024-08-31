#include <iostream>
using namespace std;
class First
{
private:
    int x = 1;

public:
    int y = 2;

protected:
    int z = 3;

public:
    void display()
    {
        cout << "hello from first class" << endl;
    }
};
class Second : protected First
{
public:
    void printX()
    {
        //! cout << "x is " << x << endl; Error
    }
    void printy()
    {
        cout << "y is " << y << endl; 
    }
    void printz()
    {
        cout << "z is " << z << endl;
    }
};
int main()
{ 
    Second ob1;
    ob1.printy();
    ob1.printz();

    return 0;
}