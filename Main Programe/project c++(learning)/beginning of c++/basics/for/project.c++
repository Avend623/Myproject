#include<iostream>
using namespace std;
int main(){
    int weeks;
    cout<<"enter your weeks: ";
    cin>>weeks;
    for(int i = 1;i <= weeks;i++){
        cout<<"week"<<i<<endl; 
        for(int j = 1;j <=7;j++){
            cout<<"   day-"<<j<<endl;
        }
    }
    
}
