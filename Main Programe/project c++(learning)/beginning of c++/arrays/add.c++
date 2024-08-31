#include <iostream>
using namespace std;
int main()
{
    bool again;
    int size;
    cout << "your range:";
    cin >> size;
    int ages[size];
    for (int i = 0; i < size; i++)
    {
        cout << "enter your ages[" << i << "]:";
        cin >> ages[i];
    }
    for (int i = 0; i < size; i++)
    {
        printf("ages[%i] = %i \n", i, ages[i]);
    }
    int element;
    int index;
    cout << "array before editing: ";
    for (int i = 0; i < size; i++)
    {
        cout << ages[i] << " ";
    }
    while (again)
    {
    cout << endl;
    cout << "enter the that element thet you want to insert :";
    cin >> element;

    cout << "index : ";
    cin >> index;
    if (index > size)
    {
        cout << "invailed index";
    }
    else
    {
        for (int i = size; i < index; i--)
        {
            ages[i] = ages[i - 1];
        }
        ages[index] = element;
        size++;
    }
    cout << "array after editing: ";
    for (int i = 0; i < size; i++)
    {
        cout << ages[i] << " ";
    }
    cout<<"do you want another one(1/0):";
    cin>>again;
}
}