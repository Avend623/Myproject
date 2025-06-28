#include<iostream>
using namespace std;
int main(){
    int x = 10;

    switch(x)
    {
        case 3:
            cout<<"x is equal 3\n";
            break;
        case 2:
            cout<<"x is equal 2\n";
            break;
        case 10:
            cout<<"x is equal 10\n";
            break;
        default:
            cout<<"x not equal any number i know\n";
    }
}