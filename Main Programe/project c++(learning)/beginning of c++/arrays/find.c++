#include <iostream>
using namespace std;
int main()
{
    int size = 5;
    int index = -1; // Initialize index to -1
    int element;
    int arr[size] = {10, 20, 30, 40, 50};
    cout << "Enter the element that you want to find: ";
    cin >> element;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            index = i;
            break; // Exit loop if element is found
        }
    }
    if (arr[index] == element) // Check if index was updated
    {
        cout << "The element " << element << " is found at index " << index << endl;
    }
    else
    {
        cout << "Element not found! Try again..." << endl;
    }
}
