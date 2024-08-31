#include<iostream>
using namespace std;
int fun(int n){
    cout<<"#";
    n--;
    if(n == 1){
        return 1;
    }
    else{
        cout<<endl;
        return fun(n) - n; 
    }
    }
    

int main(){
    int n;
    cin>>n;
    fun(n);

}