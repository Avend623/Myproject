#include<iostream>
using namespace std;
class Cal
{
    private:
        int x;
        int y;
    public:
        Cal(){
            x=20;
            y=10;
        }
        int sum();
};
int Cal::sum(){
    return x+y;
}
int main(){
    Cal ob1;
    cout<<"sum:"<<ob1.sum()<<endl;
    return 0;
}