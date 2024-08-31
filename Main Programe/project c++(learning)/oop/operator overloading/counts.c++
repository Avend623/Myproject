#include<iostream>
using namespace std ;
class Count
{
    private:
        int value;
    public:
        Count() : value(10){}
        Count operator +(Count ob)
        {
            Count sum;
            sum.value = ob.value + value;
            return sum;
        }
        void show()
        {
            cout<<"value is "<<value<<endl;
        }
};
int main()
{
    Count count1;
    Count count2;
    count1 = count2;
    Count result;
    result = count1 + count2;
    result.show();
    return 0;
}