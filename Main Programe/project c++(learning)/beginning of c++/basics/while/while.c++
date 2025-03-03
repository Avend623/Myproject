#include<iostream>
using namespace std;
int main(){
int num1;
cout<<"enter your p-num1: ";
cin>>num1;
int num2;
cout<<"enter your p-num2: ";
cin>>num2;
while (num1 >= 0 && num2 >= 0)
{
    cout<<num1<<'+'<<num2<<'='<<num1 + num2;
    return 0;
}
cout<<"invailed number"<<endl;
return 0;
}