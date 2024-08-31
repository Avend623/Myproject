#include<iostream>
using namespace std;
class YT
{
    public:
        string name;
        int age;
    
    void print(YT x);

};
void YT::print(YT x){
    cout<<"name is "<<name<<endl;
}

int main()
{
    YT ob1;
    YT ob2;
    ob1.name = "avend";
    ob1.age = 16;
    ob1.print(ob1);
    return 0;
}