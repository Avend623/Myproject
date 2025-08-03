#include<iostream>
using namespace std;
class Dontworry
{
    private:
        int x;
    public:
        void getValues()
        {
            cout<<"enter x:";
            cin>>x;
        }
        void operator == (Dontworry ob)
        {
            if(x == ob.x)
            {
                cout<< x << "==" << ob.x <<endl;
            }
            else
            {
                cout<< x << "!=" << ob.x <<endl;
            }
        }
};
int main()
{
    Dontworry ob1;
    ob1.getValues();
    Dontworry ob2;
    ob2.getValues();
    ob1 == ob2;
    return 0;
}