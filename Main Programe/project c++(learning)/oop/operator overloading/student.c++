#include <iostream>
using namespace std;
static int count = 0;
class Person
{
private:
    int age;
    string name;
    string place;

public:
    Person()
    {
        count++;
        cout << "object(" << count << ")" << endl;
        cout << "enter your name:";
        cin >> name;
        cout << "enter your age:";
        cin >> age;
        cout << "enter your place:";
        cin >> place;
    }
    void getValues()
    {
        cout << "your name is " << name<<endl;
        cout << "your age is " << age<<endl;
        cout << "your place is " << place<<endl;
    }
};
class Student : public Person
{
private:
    int grade = 0;
    int id;

public:
    Student()
    {
        cout << "enter your id:";
        cin >> id;
    }
    void getValues()
    {
        Person::getValues();
        cout << "your grade is " << grade << endl;
        cout << "your id is " << id << endl;
    }
    void midExam()
    {
        cout << "object(" << count << ")" << endl;
        cout << "enter your grade:";
        cin >> grade;
        if (grade >= 50)
        {
            cout << "you success in mid!" << endl;
        }
        else
        {
            cout << "good luck in final.." << endl;
        }
    }
    void final()
    {
        int fgrade;
        cout << "object(" << count << ")" << endl;
        cout << "enter your grade:";
        cin>>fgrade;
        grade = (grade + fgrade)/2;
        if (fgrade >= 50)
        {
            cout<<"you success in this year!!"<<endl;
        }
        else
        {
            cout<<"good luck.."<<endl;
        }
    }
};
int main()
{
    Student ob1;
    ob1.midExam();
    ob1.final();
    ob1.getValues();
    return 0;
}