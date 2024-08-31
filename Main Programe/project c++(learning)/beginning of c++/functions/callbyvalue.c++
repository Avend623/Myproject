#include<iostream>
using namespace std;
void set(int a){
    a = 0;
    cout<<"in set function/"<<a<<endl;

}
int main(){
    int a = 10; 
    cout<<"before calling set function/"<<a<<endl;
    set(a);
    cout<<"after calling set function/"<<a<<endl;
}