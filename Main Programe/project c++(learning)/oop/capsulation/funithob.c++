#include <iostream>
using namespace std;
class School
{
private:
    string name;
    int mark;

public:
    School(string n, int m)
    {
        name = n;
        mark = m;
    }
    void show()
    {
        cout << "your name is " << name << endl;
        cout << "your mark is " << mark << endl;
    }
    void sum(School ob1, School ob2)
    {
        cout << ob1.mark + ob2.mark;
    }
};
int main()
{
    School ob1("avend", 15);
    School ob2("anas", 20);
    ob1.sum(ob1, ob2);

    return 0;
}