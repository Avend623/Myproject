#include <iostream>
using namespace std;
class Stu
{
private:
    string name;
    int mark;

public:
    Stu(string n, int m)
    {
        name = n;
        mark = m;
    }
    Stu()
    {
        cout << "your name ";
        cin >> name;
        cout << "your mark";
        cin >> mark;
    }
    friend void sum(Stu ob1, Stu ob2, Stu ob3);
    int checkmark(Stu ob1, Stu ob2, Stu ob3);
};
int Stu ::checkmark(Stu ob1, Stu ob2, Stu ob3)
{
    if (ob1.mark > ob2.mark && ob1.mark > ob3.mark)
    {
        cout << ob1.name << "'s mark is the biggest one " << ob1.mark << endl;
    }
    else if (ob2.mark > ob1.mark && ob2.mark > ob3.mark)
    {
        cout << ob2.name << "'s mark is the biggest one " << ob2.mark << endl;
    }
    else if(ob3.mark > ob1.mark && ob3.mark > ob2.mark)
    {
        cout << ob3.name << "'s mark is the biggest one " << ob3.mark << endl;
    }
    else
    {
        cout<<"all the marks are equal"<<endl;
    }
}
void sum(Stu ob1, Stu ob2, Stu ob3)
{
    int sum = ob1.mark + ob2.mark + ob3.mark;
    cout << "Total mark:" <<sum<< endl;
}
int main()
{
    Stu ob1("Ahmed", 100);
    Stu ob2("Ali", 15);
    Stu ob3("Nour", 10);
    sum(ob1,ob2,ob3);
    ob1.checkmark(ob1,ob2,ob3);
    return 0;
}