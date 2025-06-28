#include <iostream>
using namespace std;
class School
{
private:
    string name;
    int level;
    int id;

public:
    void set(string n, int l);
    void set(int i);
};
void School::set(string n, int l)
{
    name = n;
    level = l;
    cout << "your name is " << name << endl;
    cout << "your level is " << level << endl;
}
void School::set(int i)
{
    id = i;
    cout << "your id is " << id << endl;
}
int main()
{
    School ob1;
    ob1.set("avend", 99);
    ob1.set(1533300153);
    return 0;
}