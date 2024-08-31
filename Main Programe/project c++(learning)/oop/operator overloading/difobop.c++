#include <iostream>
using namespace std;

class Count {
    private:
        int value = 0;
    public:
        Count() : value(5) {}
        void display() {
            cout << "value is " << value << endl;
        }
        Count operator++()
        {
            ++value;
            return *this;
        }
        void operator=(const Count& ob) 
        {
            value = ob.value;
        }
};
int main() {
    Count count1;
    Count count2;
    count1.display();
    count2.display();
    count1 = ++count2;
    count1.display();
    return 0;
}
