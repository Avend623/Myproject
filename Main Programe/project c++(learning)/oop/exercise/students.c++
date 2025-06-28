#include <iostream>
using namespace std;
class Student
{
private:
    string name;
    int age;
    int grade;
    int id;

public:
    Student(string n,int a,int g,int i)
    {
        name = n;
        age = a;
        grade = g;
        id = i;
    }
    void show(Universe ob)
    {
        cout<<ob.name;
    }
    friend class Universe;//* you sent date from this class (you are his friend "!you don't know about him!")
};
class Universe
{
    string name = "earth";
    public:
        void print(Student ob)
        {
            cout<<"your name is "<<ob.name<<endl;
            cout<<"your age is "<<ob.age<<endl;
            cout<<"your grade is "<<ob.grade<<endl;
            cout<<"your id is "<<ob.id<<endl;
        }
        friend Student;//* (you trust him and you give him your sectrets but you don't know about him) you sent date from this class (you are his friend "!you don't know about him!")
};
int main()
{
    Student ob1("Avend",15,98,1001041);
    Universe ob2;
    ob2.print(ob1);
    return 0;
}