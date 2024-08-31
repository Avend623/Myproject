#include<iostream>
using namespace std;
class Company{
    private:
        string name;
        int id;
        int sal;
    public:
        void add();
        void print();
};
void Company::add(){
    int id;
    int sal;
    cout<<"enter your name:";
    cin>>name;
    cout<<"enter your id:";
    cin>>id;
    cout<<"enter your sal:";
    cin>>sal;
}
void Company::print(){
    cout<<"your name is "<<name<<endl;
    cout<<"your id is "<<id<<endl;
    cout<<"your sal is "<<sal<<endl;
}
int main()
{
    Company ob1;
    string name;
    ob1.add();
    ob1.print();

    
    return 0;
}