#include<iostream>
using namespace std;
void sum(){
    cout<<"unknown"<<endl;
}
void sum(int a){
    cout<<a<<endl;
}
void sum(int a,int b){
    cout<<a+b<<endl;
}
void sum(int a,int b,int c){
    cout<<a+b+c<<endl;
}
void sum(double a,double b,double c,double d){
    cout<<a+b+c+d<<endl;
}

int main(){
    sum();
    sum(2);
    sum(4,3);
    sum(4,3,4);
    sum(4.4,2.4,2.6,2.3);

}