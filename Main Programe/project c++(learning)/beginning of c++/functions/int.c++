#include<iostream>
using namespace std;

float sum(float a, float b)
{
   return a+b;

}
int main(){
    float num1;
    float num2;
    cout<<"num1:";
    cin>>num1;
    cout<<"num2:";
    cin>>num2;
    
    int x = sum(num1,num2);
    cout<<x;
    if (x%2 == 0)
    {
        cout<<",it's even number";
        return 0;
    }
    else{
        cout<<",it's odd number";
        return 0;
    }
    return 1;
}