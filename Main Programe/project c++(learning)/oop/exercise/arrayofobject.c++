#include<iostream>
using namespace std;
class Student
{
    private:
        string name;
        int age;
        int mark;
    public:
        void setValue()
        {
            cout<<"Give me your information please!"<<endl;
            cout<<"enter your name:";
            cin>>name;
            cout<<"enter your age:";
            cin>>age;
            cout<<"enter your mark:";
            cin>>mark;
        }
};
int main()
{
    int size = 4;
    Student ob[size];
    for (int i = 0; i < size; i++)
    {
        ob[i].setValue();
    }
    
    return 0;
}