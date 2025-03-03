#include<iostream>
using namespace std;

int main(){
    int num;
    cout<<"print your number:";
    cin>>num;
    if (num != 0)
    {
    if (num%2 == 0)
    {
        cout<<"your number is even"<<endl;
        return 0;
    }
    else{
        cout<<"your number is odd"<<endl;
        return 0;
    }
    }
    else{
        cout<<"your number isn't odd or even"<<endl;
        return 0;
    }
    
}