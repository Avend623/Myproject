#include<iostream>
using namespace std;
class YT{
    private:
        string name;
        int sub;
        int videos;
    public:
        void add(string n, int s, int v);
        void print();
};
void YT::add(string n, int s, int v){
    name = n;
    sub = s;
    videos = v;
}
void YT::print(){
    cout<<"your name is "<<name<<endl;
    cout<<"your sub is "<<sub<<endl;
    cout<<"your videos is "<<videos<<endl;
}
int main()
{
    YT ob1;
    YT ob2;
    ob1.add("Avend",188,35);
    ob2.add("Ahmed",100,23000);
    ob1.print();
    ob2.print();
    
    return 0;
}