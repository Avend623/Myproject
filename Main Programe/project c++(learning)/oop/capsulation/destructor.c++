#include <iostream>
using namespace std;
class Sample
{
private:
    int x;
    int y;
public:
    Sample()
    {
        x=20;
        y=20;
    }
    ~Sample()
    {
        cout<<"bye"<<endl;
    }
    void show(){
        cout<<"x is "<<x<<endl;
        cout<<"y is "<<y<<endl;
    }

};
int main()
{
    Sample ob1;
    ob1.~Sample();
    ob1.show();
    return 0;
}