#include <iostream>
using namespace std;
/*
take the day number and print correspondance day
for 1 print Monday,
for 2 print Tuesday and so on..
*/

int main()
{
    int day;
    cin >> day;
    switch (day)
    {
    case 1:
        cout << "Monday" << endl;
        break;

    case 2:
        cout << "Tuesday" << endl;
        break;
    case 3:
        cout << "Wednesday" << endl;
        break;
    case 4:
        cout << "Thursday" << endl;
        break;
    case 5:
        cout << "Friday" << endl;
        break;
    case 6:
        cout << "Saturday" << endl;
        break;
    case 7:
        cout << "Sunday" << endl;
        break;

    default:
        cout << "Enter valid Number";
        break;
    }
    return 0;
}