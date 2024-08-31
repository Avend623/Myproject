#include <iostream>
using namespace std;
double discount(double price, double rate);
void print(double LPRICE);
int main()
{
    double rate;
    cout << "enter your discount rate:";
    cin >> rate;
    double price;
    cout << "enter your price: ";
    cin >> price;
    print(discount(price, rate));//* cout<<"you should pay:"<<discount(price,rate)
}
double discount(double price, double rate)
{
    double LPrice = price - price * rate / 100;
    return LPrice;
}
void print(double LPRICE){
    cout<<"you should pay:"<<LPRICE;
}
