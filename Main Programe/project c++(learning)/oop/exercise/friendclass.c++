#include<iostream>
using namespace std;
class Student2;
class Student1
{
    private:
        int mark1;
        string name;
    public:
        Student1(int m , string n)
        {
            mark1 = m;
            name = n;
        }
        void print()
        {
            cout<<"your name is "<<name<<endl;
            cout<<"your mark is "<<mark1<<endl;
        }
        friend class Student2;
        
};
class Student2
{
    private:
        int mark2;
        string name;
    public:
        Student2(string n)
        {
            name = n;
        }
        void print()
        {
            cout<<"your name is "<<name<<endl;
            cout<<"your mark is "<<mark2<<endl;
        }
        void setMark(Student1 ob)
        {
            mark2 = ob.mark1;
        }
};
int main()
{
    Student1 ob1(100,"Avend");
    Student2 ob2("Anas");
    ob2.setMark(ob1);
    ob2.print();
    return 0;
}