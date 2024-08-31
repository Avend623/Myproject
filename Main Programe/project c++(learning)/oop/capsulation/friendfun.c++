#include <iostream>
using namespace std;
class Stu
{
    int mark;

public:
    Stu(int m)
    {
        mark = m;
    }
    friend void show(Stu ob1);
};
void show(Stu ob1)
{
    cout << "your mark is " << ob1.mark;
}
int main()
{
    Stu ob1(388);
    show(ob1);
}