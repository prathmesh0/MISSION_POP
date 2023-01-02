#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<int, 3> arr1;       //-->{?,?,?}
    array<int, 5> arr2 = {1}; //-->{1,0,0,0,0}

    for (auto it = arr2.begin(); it != arr2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    arr1.fill(10); // fill function
    for (auto it = arr1.begin(); it != arr1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    array<int, 5> arr3 = {1, 3, 5, 6, 7};
    // various type to print array element
    // rbegin(),rend(),end(),begin() function
    for (auto it = arr3.begin(); it != arr3.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    for (auto it = arr3.begin(); it != arr3.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    for (auto it = arr3.rbegin(); it != arr3.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    for (auto it = arr3.end() - 1; it >= arr3.begin(); it--)
    {
        cout << *it << " ";
    }
    cout << endl;

    for (auto it : arr3)
    {
        cout << it << " ";
    }
    cout << endl;

    string s = "mangesh";
    for (auto it : s)
    {
        cout << it << " ";
    }
    cout << endl;

    cout << arr3.size() << endl;  // size
    cout << arr3.front() << endl; // front
    cout << arr3.back() << endl;  // back
    cout << endl;
    cout << endl;
    cout << endl;
    return 0;
}