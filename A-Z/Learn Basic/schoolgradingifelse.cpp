#include <iostream>
using namespace std;
/*
A school has following grading system:
below 25 - F
25 to 44 - E
45 to 49 - D
50 to 59 - C
60 to 79 - B
80 to 100 - A
print grade acc.to user input marks
*/

int main()
{
    int marks;
    cin >> marks;
    // if (marks < 25)
    //     cout << "F" << endl;

    // if (marks >= 25 && marks <= 44)
    //     cout << "E" << endl;

    // if (marks >= 45 && marks <= 49)
    //     cout << "D" << endl;

    // if (marks >= 50 && marks <= 59)
    //     cout << "C" << endl;

    // if (marks >= 60 && marks <= 79)
    //     cout << "B" << endl;

    // if (marks >= 80 && marks <= 100)
    //     cout << "A" << endl;

    if (marks < 25)
        cout << "F" << endl;

    else if (marks <= 44)
        cout << "E" << endl;

    else if (marks <= 49)
        cout << "D" << endl;

    else if (marks <= 59)
        cout << "C" << endl;

    else if (marks <= 79)
        cout << "B" << endl;

    else
        cout << "A" << endl;

    return 0;
}