#include<iostream>
using namespace std;
const int numbers = 5;
class Student
{
    private:
        int mark;
    public:
        Student()
        {
            cout<<"enter your mark:";
            cin>>mark;
        }
        friend void average(Student ob[numbers]);
};
void average(Student ob[numbers])
{
    int average = 0;
    for (int i = 0; i < numbers; i++)
    {
        average+=ob[i].mark;
    }
    cout<<"average of students:"<<average/numbers<<endl;
    
}
int main()
{
    Student ob[numbers];
    average(ob);
    
    return 0;
}