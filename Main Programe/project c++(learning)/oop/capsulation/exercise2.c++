#include<iostream>
using namespace std;
class Circle{
    private:
        double radius;
    public:
        void setvalue(){
            double rad;
            cout<<"enter your radius:";
            cin>>rad;
            radius = rad;
        }
        void print(){
            double area;
            area = 3.14*radius*radius;
            cout<<"the area of circle is "<<area;
        }
};
int main(){
    Circle ob1;
    ob1.setvalue();
    ob1.print();

    return 0;
}