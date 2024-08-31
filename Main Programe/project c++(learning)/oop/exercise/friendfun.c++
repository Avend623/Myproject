#include<iostream>
using namespace std;
class Stu
{
    private:
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
    cout<<"your mark is "<<ob1.mark<<endl;
}
int main()
{
    Stu ob1(100);
    show(ob1);
    return 0;
}