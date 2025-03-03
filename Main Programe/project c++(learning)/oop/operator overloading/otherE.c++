#include<iostream>
using namespace std;
class Test
{
    private:
        int x;
    public:
        Test()
        {
            cout<<"enter value of X:";
            cin>>x;
        }
        void getValues()
        {
            cout<<"X is "<<x<<endl;
        }
        int operator *=(int num)
        {
            return x *= num;
        }
        int operator -=(int num)
        {
            return x -= num;
        }
        int operator +=(int num)
        {
            return x += num;
        }
        int operator /=(int num)
        {
            return x /= num;
        }
        int operator %=(int num)
        {
            return x += num;
        }
};
int main()
{
    Test ob1;
    ob1.getValues();
    cout<<(ob1%=20)<<endl;
    cout<<(ob1*=20)<<endl;
    cout<<(ob1-=20)<<endl;
    cout<<(ob1+=20)<<endl;
    cout<<(ob1/=20)<<endl;
    return 0;
}