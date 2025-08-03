#include<iostream>
using namespace std;
class Book{
    public:
        string title;
        string author;
        int price;
        int pages;

};
int main(){
    Book book1;
    book1.title = "c++ level 1";
    book1.author = "Ahmed";
    book1.price = 10;
    book1.pages = 200;

    cout<<"book1"<<endl;
    cout<<"book1 title "<<book1.title<<endl;
    cout<<"book1 author "<<book1.author<<endl;
    cout<<"book1 price "<<book1.price<<endl;
    cout<<"book1 pages "<<book1.pages<<endl;

    Book book2;
    book2.title = "c++ level 2";
    book2.author = "mohamed";
    book2.price = 10;
    book2.pages = 200;

    cout<<"book2"<<endl;
    cout<<"book2 title "<<book2.title<<endl;
    cout<<"book2 author "<<book2.author<<endl;
    cout<<"book2 price "<<book2.price<<endl;
    cout<<"book2 pages "<<book1.pages<<endl;


    return 0;
}