#include <iostream>
using namespace std;

int main()
{
    int age;
    cin >> age;
    if (age >= 18)
        cout << "you are an adult" << endl;
    else
        cout << "you are not an adult" << endl;
    return 0;
}