#include<iostream>
using namespace std;
class Form
{
    private:
        string name;
    public:
        Form()
        {
            cout<<"enter your name:";
            cin>>name;
        }
        void operator +(Form ob)
        {
            cout<<name<<" "<<ob.name<<endl;
        }
};
int main()
{
    Form ob1;
    Form ob2;
    ob1 + ob2;
    return 0;
}
