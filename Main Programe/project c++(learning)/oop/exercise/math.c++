#include <iostream>
using namespace std;
static int counter = 1; // Declare num as static
class Rect
{
private:
    float width;
    float length;

public:
    Rect()
    {
        cout << "This is rectangle num " << counter << endl;
        cout << "enter rectangle width:" << endl;
        cin >> width;
        cout << "enter rectangle length:" << endl;
        cin >> length;
        counter++;
    }
    Rect(float w, float l)
    {
        counter += 1;
        cout << "This is rectangle num " << counter << endl;

        width = w;
        length = l;
    }
    float rectArea()
    {
        return length * width;
    }
    void print();
    friend void comp(Rect ob1, Rect ob2);
};
void Rect::print()
{
    cout << "your rectangle width is " << width << endl;
    cout << "your rectangle length is " << length << endl;
}

void comp(Rect ob1, Rect ob2)
{
    if (ob1.rectArea() > ob2.rectArea())
    {
        cout << "your first rectangle is bigger . ." << ob1.rectArea() << endl;
    }
    else if (ob1.rectArea() < ob2.rectArea())
    {
        cout << "your second rectangle is bigger . ." << ob2.rectArea() << endl;
    }
    else
    {
        cout << "your rectangles are equal . ." << endl;
    }
}

int main()
{
    Rect ob1;
    ob1.print();
    Rect ob2;
    ob2.print();
    Rect ob3;
    ob3.print();
    comp(ob1, ob2);
    return 0;
}
