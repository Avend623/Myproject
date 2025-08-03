#include<iostream>
using namespace std;
int main(){
    int x = 10;
    
    x*=2;

    cout<<x<<endl;//* 20

    int y = 4;

    y=+2; //* اذا اتى خطأ عندما نكتب ضرب او قسمة بعد اليساوي اعرف بانها تجعل الرقم ولا تضيف عليه

    cout<<y<<endl;//* 2

    cout<<(x+=2)<<endl;

    cout<<(x%=2)<<endl;


}