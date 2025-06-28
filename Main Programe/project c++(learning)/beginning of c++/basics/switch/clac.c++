#include<iostream>
using namespace std;
int main (){
    char symbol;
    cout<<"enter your symbol: ";
    cin>>symbol;
    int num1;
    cout<<"enter your first number:";
    cin>>num1;
    int num2;
    cout<<"enter your second number:";
    cin>>num2;    
    if (symbol == '/' && num2 == 0)
    {
        cout<<"invailed equation . .";
    }
    
    switch (symbol)
    {
    case '+':
        cout<<"equal:"<<num1 + num2;
        break;
    case '-':
        cout<<"equal:"<<num1 - num2;
        break;
    case 'x':
        cout<<"equal:"<<num1 * num2;
        break;
    case '/':
        cout<<"equal:"<<num1 / num2;
        break;
    default:
        cout<<"ivailed symbol . .";
        break;
    }
}