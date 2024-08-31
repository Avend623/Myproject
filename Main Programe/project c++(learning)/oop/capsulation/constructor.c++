#include <iostream>
using namespace std;
class Test
{
private:
    int a;
    int b;

public:
    Test(){
        cout<<"hi i am default construtor\n";
    }
    Test(int x,int y)
    {
        a=x;
        b=y;
    }
    void show()
    {
        cout << "A = " << a << endl;
        cout << "B = " << b << endl;
    }
};
int main()
{
    Test ob1;
    Test ob2(10,20);
    return 0;
}