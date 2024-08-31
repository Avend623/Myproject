#include<iostream>
using namespace std;
class Company
{
    public:
        int id;
        string name;
        float salary;
    void save(int i, string n,float sal)
    {
        id = i;
        name=n;
        salary=sal;
    }
    void display(){
        cout<<id<<" "<<name<<" "<<salary<<endl;
    }
};
int main()
{
    Company ob1;
    ob1.save(1,"ahmed",10.2);
    ob1.display();
    
return 0;   
}

