#include <iostream>
using namespace std;

int main()
{
    // string name = "Prathmesh";
    // cout << name << endl;
    // string color;
    // cin >> color;
    // cout << color << endl;
    // getline function --> to take the input string with the space
    // string s;
    // getline(cin, s);
    // cout << s << endl;

    string x = "Prathmesh", y = "Parab";
    // append()
    cout << x + y << endl;

    // assign
    string c;
    c.assign(x);
    cout << c << endl;
    // at()
    cout << c.at(4);

    // clear()
    c.clear();
    cout << c << endl;

    // empty()
    if (c.empty())
    {
        cout << "empty" << endl;
    }
    else
    {
        cout << "not empty" << endl;
    }

    // erase()
    string hero = "Akshay";
    hero.erase(hero.begin(), hero.begin() + 2);
    cout << hero << endl;
    // length()
    cout << hero.length() << endl;
    return 0;
}