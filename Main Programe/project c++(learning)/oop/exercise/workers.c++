#include <iostream>
using namespace std;
class Workers
{
private:
    string name;
    int salary;

public:
    Workers(string n, int s)
    {
        name = n;
        salary = s;
    }
    void show();
    friend void sumSalaries(Workers ob1, Workers ob2, Workers ob3);
};
void Workers :: show()
{
    cout << "your name is " << name << endl;
    cout << "your salary is " << salary << endl;
}
void sumSalaries(Workers ob1, Workers ob2, Workers ob3)
{
    int sum = (ob1.salary + ob2.salary + ob3.salary) / 3;
    cout << "total of salries:" << sum << endl;
}
int main()
{
    Workers ob1("Ahmed", 24000);
    ob1.show();
    Workers ob2("Sami", 23000);
    ob2.show();
    Workers ob3("Sara", 25000);
    ob3.show();
    sumSalaries(ob1, ob2, ob3);
    return 0;
}