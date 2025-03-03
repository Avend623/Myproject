#include<iostream>
using namespace std;
int main(){
    int arr[5] = {5,4,6,4,1};
    cout<<"arr[0] = "<<arr[0]<<endl;
    cout<<"arr[1] = "<<arr[1]<<endl;
    cout<<"arr[2] = "<<arr[2]<<endl;
    cout<<"arr[3] = "<<arr[3]<<endl;
    cout<<"arr[4] = "<<arr[4]<<endl;

    int x = 10;
    x = 12;
    arr[0] = 12;
    cout<<"arr[0] = "<<arr[0]<<endl;

}