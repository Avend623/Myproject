#include<iostream>
using namespace std;
void biggest(int num1,int num2,int num3){
    if(num1 > num2 && num1 > num3){
        cout<<"number1 = "<<num1<<" is the biggest one . ."<<endl;
    }
    else if(num2 > num1 && num2 > num3){
        cout<<"number2 = "<<num2<<" is the biggest one . ."<<endl;
    }
    else if(num3 > num1 && num3 > num2){
        cout<<"number3 = "<<num3<<" is the biggest one . ."<<endl; 
    }
    else{
        cout<<"no one is the biggest";
    }
}
int main(){
    int num1,num2,num3;
    cout<<"enter your num1:";
    cin>>num1;
    cout<<"enter your num2:";
    cin>>num2;
    cout<<"enter your num3:";
    cin>>num3;
    biggest(num1,num2,num3);

}