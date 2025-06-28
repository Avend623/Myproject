#include<iostream>
using namespace std;
int main(){
    int x = 4; 
    int y = 10;

    cout<<x+3<<endl;// 7 // 4
    cout<<x<<endl;// 4
    cout<<y++<<endl;//10 //11
    cout<<++y<<endl;//12 //12
    cout<<++x<<endl;//5 //5
    cout<<x<<endl;//5
    cout<<x++<<endl;//5 //6
    cout<<y+x<<endl;//18
    cout<<y<<endl;//12
    cout<<x<<endl;//6

}