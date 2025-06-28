#include <iostream>
using namespace std;
class Company
{
private:
    string name;
    int id;
    int salary;
public:
    void print()
    {
        cout << name << " " << id << " " << salary << endl;
    }
    void add(string n,int i,int sal){
        name = n;
        id = i;
        salary = sal;
    }
};
int main()
{
    Company ob1;
    ob1.add("ahmed",122,500);
    ob1.print();

    return 0;
}