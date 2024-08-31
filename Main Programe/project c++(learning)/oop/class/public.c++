#include<iostream>
using namespace std;
class Book{
    public:
        int price;
        int pages;
        string name;
};
int main(){
    Book ob1;
    ob1.price = 10;
    ob1.pages = 200;
    ob1.name = "c++ level 1";

    cout<<"the name of book is "<<ob1.name<<endl;

    return 0;
}