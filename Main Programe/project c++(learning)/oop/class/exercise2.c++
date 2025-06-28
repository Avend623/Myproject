#include<iostream>
using namespace std;
class YT
{
    public:
        string name;
        int age;
    
    void print(YT ob);
    void set(YT ob1);

};
void YT::print(YT ob){
    cout<<name<<endl;
}
void YT::set(YT ob1){
    cout<<ob1.name;
}

int main()
{
    YT ob1;
    YT ob2;
    ob1.name = "i am proud of you";
    ob2.name = "keep going";
    ob2.print(ob1);
    ob1.set(ob2);
    return 0;
}