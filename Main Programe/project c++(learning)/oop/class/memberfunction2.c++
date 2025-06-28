#include<iostream>
using namespace std;
class rect
{
    public:
        int width;
        int height;
    int print();
};
int rect::print(){
    return width*height;
}


int main(){
    rect ob1;
    ob1.width = 10;
    ob1.height = 3;


    rect ob2;
    ob2.width = 20;
    ob2.height = 30;

    cout<<ob1.print()<<endl;
    cout<<ob2.print()<<endl;

    return 0;
}