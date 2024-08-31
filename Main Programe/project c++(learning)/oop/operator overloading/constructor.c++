#include<iostream>
using namespace std;
int static count = 0;
class Count
{
    private:
        int value;
    public:
        Count() : value(20)
        {
            cout<<"object "<<++count<<endl;
            cout<<"value is "<<value<<endl;
        }

};
int main()
{
    Count ob1;
    return 0;
};