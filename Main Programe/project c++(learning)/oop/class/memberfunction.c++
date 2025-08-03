#include<iostream>
using namespace std;
class Book{
    public:
        string title;
        int price;
        int pages;
        string author;
    void print(){
        cout<<"title "<<title<<endl;
        cout<<"price "<<price<<endl;
        cout<<"pages "<<pages<<endl;
        cout<<"author "<<author<<endl;
    }

};
int main(){
    Book ob1;
    Book ob2;
    ob1.title = "c++";
    ob1.price = 120;
    ob1.pages = 200;
    ob1.author = "ahemd";

    ob1.print();


    return 0;
}