#include<iostream>
using namespace std;
void set(int *x,int *y){
    int z;
    cout<<x<<endl;
    cout<<y<<endl;
    z = *x;
    *x = *y;
    *y = z;
}
int main(){
    int x = 1;
    int y = 2;
    cout<<"x is:"<<x<<endl;
    cout<<"y is:"<<y<<endl;
    set(&x,&y);
    cout<<"x is:"<<x<<endl;
    cout<<"y is:"<<y<<endl;
}