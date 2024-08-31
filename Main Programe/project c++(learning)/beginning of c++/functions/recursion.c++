#include<iostream>
using namespace std;
int fun(int n){
    if(n == 0){
        return 1;
    }
    else{
        return 7+fun(n-2);
    }
    
}
int main(){
    cout<<fun(4)<<endl;
}