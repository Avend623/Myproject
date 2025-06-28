#include <iostream>
using namespace std;
class Book
{
public:
    int page;
    string name;
    Book()
    {
        cout << "hi i am constructor\n";
    }
    void print()
    {
        cout << "hi i am function\n";
        cout << name << endl;
        cout << page << endl;
    }
};

int main()
{
    Book ob;
    Book ob2;
    ob.name = "ahmed";
    ob.page = 200;
    return 0;
}