#include <iostream>
using namespace std;
class Car
{
private:
    string name;
    int price;

public:
    Car(string n, int p);
    void display();
    friend void increase(Car ob);
};

Car :: Car(string n, int p)
{
    name = n;
    price = p;
}

void Car::display()
{
    cout << "your car price is " << price << endl;
}

void increase(Car ob)
{
    ob.price += 1000;
    cout << "your car price after increase is " << ob.price << endl;
}
int main()
{
    Car ob1("Nissan sentra 2020", 14000);
    ob1.display();
    increase(ob1);
    return 0;
}