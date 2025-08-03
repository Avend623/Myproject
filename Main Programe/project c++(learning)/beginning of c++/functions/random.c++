#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;
int main(){
    srand(time(0));
    for (int i = 0; i < 11; i++)
    {
        cout<<1 + rand()%(6-1+1)<<endl;
    }//* start + rand() % (end - start + 1)
    
}