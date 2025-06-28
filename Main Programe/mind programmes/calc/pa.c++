#include <iostream>
using namespace std;
int add(int num1, int num2)
{
    return num1 + num2;
}
int subtruct(int num1, int num2)
{
    return num1 - num2;
}
int divide(int num1, int num2)
{
    return num1 / num2;
}
int multiply(int num1, int num2)
{
    return num1 * num2;
}
long factrolize(int num){
    for(int i = num; i >= 1;){
        i--;
        num = num*i;
        if (i == 1)
        {
            return num;
            break;
        }
        
    }
    
}
int main()
{
    bool x = true;
    char sym;
    while (x)
    {
        
        cout << "enter your charecter:";
        cin >> sym;
        if(sym == 'f'){
            int num;
            cout<<"enter your num:";
            cin>>num;
            cout<<"equal:"<<factrolize(num)<<endl;
        }
        if (sym == '+' || sym == '-' || sym == '*' || '/' )
        {
            int num1;
            int num2;
            cout << "enter your num1:";
            cin >> num1;
            cout << "enter your num2:";
            cin >> num2;
            switch (sym)
            {
            case '+':
                cout << "result:" << add(num1, num2);
                break;
            case '-':
                cout << "result:" << subtruct(num1, num2);
                break;
            case '*':
                cout << "result:" << multiply(num1, num2);
                break;
            case '/':
                cout << "result:" << divide(num1, num2);
                break;
            default:
                cout << "\nwrong char..\n";
            }
        }
        else{
            cout<<"\nwrong cahrecter";
        }
        cout << "\ndo you want another calc (y/n)";
        char y;
        cin >> y;
        if (y == 'y')
        {
        }
        else
        {
            break;
        }
    }
    system("pause");
}