#include<iostream>
using namespace std;

int main(){

    int z  =12;
    int a = 11;

    if (a==10)
    {
        cout<<"a is less than 20\n";//* ifانت بهذا الشكل تقل له اذا لم يتحقق الشرط الاول بخلاف ال else if اذا كتبت 
    }
    else if (a==11)
    {
        cout<<"value of a is 11\n";
    }
    else if (z==12)
    {
        cout<<"value of z is 12\n";
    }
    else{
        cout<<"nothing true\n";
    }
    
    
    
    return 0;
}