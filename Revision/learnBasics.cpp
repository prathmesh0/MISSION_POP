#include <iostream> // PreProcessor Directives
using namespace std;

// pass by value
void function(int p, int q) // formal parameter
{
    p = p + 10;
    q = q + 20;
    cout << "values of p and q in function" << endl;
    cout << p << " " << q << endl;
}

// pass by reference
void function1(int &p, int &q) // formal parameter
{
    p = p + 10;
    q = q + 20;
    cout << "values of p and q in function1" << endl;
    cout << p << " " << q << endl;
}
int main()
{
    // User Input and OutPut

    int num;
    cout << "Enter a number :" << endl;
    cin >> num;
    cout << "The entered number is " << num << endl;

    // Data Types
    cout << "size of int " << sizeof(int) << endl;
    cout << "size of float " << sizeof(float) << endl;
    cout << "size of char " << sizeof(char) << endl;
    cout << "size of double " << sizeof(double) << endl;
    // Datatypes Modifiers
    // Signed - int, char (long prefix)
    // Unsigned - int, char (short prefix)
    // long - int, double
    // short - int, double

    // Operators in C++
    /*
   1) Arithmetic --> Unary--> ++,-- Binary--> +,-,/,%
   2) Relational Operator --> ==, !=, <=, >= <, >
   3) Logical Operator --> &&, ||, !
   4) Bitwise operator --> &, |, ^, <<, >>, ~
   5) Assignment operator --> =, +=, -=
   6) Other Operator -->sizeof(), ?(Conditional Operator), ,(Comma Operator)
*/
    // If else
    int age;
    cout << "Enter Your Age :" << endl;
    cin >> age;
    if (age > 18)
    {
        cout << "You are above 18" << endl;
    }
    else
    {
        cout << "You are above below 18" << endl;
    }

    // switch Statement
    int x;
    cin >> x;
    switch (x)
    {
    case 1:
        cout << "Monday" << endl;
        break;
    case 2:
        cout << "TuesDay" << endl;
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
        cout << "Enter a valid number.. " << endl;
        break;
    }

    // Loops  inC++
    // for loop
    int number;
    cout << "enter a number" << endl;
    cin >> number;
    for (int i = 1; i <= 10; i++)
    {
        cout << number << " * " << i << " = " << (number * i) << endl;
    }

    // while loop
    // print 1-10 number
    int i = 1;
    while (i <= 10)
    {
        cout << i << endl;
        i++;
    }

    // do while
    int y = 1;
    do
    {
        cout << "MISSION POP" << endl;
        y++;

    } while (y <= 5);

    // continue and break

    for (int i = 0; i < 10; i++)
    {
        if (i == 5)
        {
            break;
        }
        cout << i << endl;
    }

    for (int i = 0; i <= 10; i++)
    {
        if (i == 5)
            continue;
        cout << i << endl;
    }

    // function
    // 1)Pass by value
    int p = 10, q = 12;
    function(p, q);
    cout << "values of p and q in main function" << endl;
    cout << p << " " << q << endl;

    // 2)Pass by reference
    function1(p, q);
    cout << "values of p and q in main function" << endl;
    cout << p << " " << q << endl;

    // Arrays and string
    // declaration of an array
    int arr[5] = {19, 34, 3, 44, 33};
    cout << arr[0] << endl;
    cout << arr[4] << endl;
    // size of an array
    int size = sizeof(arr) / sizeof(int);
    cout << "Size of an array = " << size << endl;

    // Multidimensional array
    int nums[3][3] = {{1, 12, 3}, {33, 34, 21}, {12, 33, 44}};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }

    // string
    string str = "Nook";
    cout << str << endl;
    // all character of string with N
    string s(5, 'N');
    cout << s << endl;
    //
    // string name = "prathmesh parab";
    // cout << name << endl;

    // take input from the user
    string name;
    // cin >> name;
    getline(cin, name);
    cout << name << endl;

    // string functions
    string s1 = "Pop";
    string s2 = "HOP";
    cout << s1.append(s2) << endl;
    string s3;
    cout << s3.assign(s1) << endl;
    cout << s1.at(0) << endl;
    s1.clear();
    cout << s1 << endl;
    s1 = "POP";
    cout << s1.compare(s2) << endl;

    // time and space complexity analyzation
    return 0;
}