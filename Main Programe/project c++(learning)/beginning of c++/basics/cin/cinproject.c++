#include<iostream>
using namespace std;

int main()
{
    string name ="unknow";
    int age = 0;
    double gpa = 0;
    char grade = 'a';
    bool success = true;

    cout<<"enter your name:";
    cin>>name;
    cout<<"enter your age:";
    cin>>age;
    cout<<"enter yor gpa:";
    cin>>gpa;
    cout<<"enter your grade:";
    cin>>grade;
    cout<<"enter your success:";
    cin>>success;
    cout<<endl;
    cout<<"your name is "<<name<<endl;
    cout<<"your age is "<<age<<endl;
    cout<<"your gpa is "<<gpa<<endl;
    cout<<"your grade is "<<grade<<endl;
    if(success){
        cout<<"congratolation";
    }
    else{
        cout<<"never mind";
    }
}