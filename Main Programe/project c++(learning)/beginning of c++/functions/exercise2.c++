#include<iostream>
using namespace std;
int main(){
    int x = 1;
    int y = 2;
    int temp;
    temp = x;
    x = y;
    y = temp;
    
    cout<<x<<endl;
    cout<<y<<endl;

}