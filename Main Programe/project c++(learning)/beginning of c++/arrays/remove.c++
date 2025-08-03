#include<iostream>
using namespace std;
int main(){
    int size = 5;
    int index;
    int arr[size] = {4,2,19,16,1};
    int element;
    cout<<"array before editing ";
    for(int i = 0; i < size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"enter your element that you want to remove:";
    cin>>element;
        for (int i = 0; i < size; i++)
        {
           if(element == arr[i]){
            index = i;
           }
        }
        for (int i = index; i < size-1; i++)
        {
            arr[i] = arr[i+1];
        }
        
        size--;
        
cout<<"array after editing ";
for(int i = 0; i < size;i++){
    cout<<arr[i]<<" ";
    }
}