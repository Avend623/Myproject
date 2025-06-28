#include<iostream>
using namespace std;
int main(){
    int arr[4] = {4,2,5,2};
    for (int i = 0; i < 4; i++)
    {
        cout<<&arr[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < 4; i++)
    {
        cout<<arr+i<<endl;
        cout<<*(arr+i)<<endl;
    }

    
}