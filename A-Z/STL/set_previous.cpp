#include <iostream>
#include <set>
#include <iterator>
using namespace std;

int main()
{

    set<int> s;
    s.insert(1);
    s.insert(22);
    s.insert(13);
    s.insert(4);
    set<int, greater<int>>::iterator itr;
    cout << "\nThe set s is : \n";
    for (itr = s.begin(); itr != s.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;

    // assigning the elements from s to s1
    set<int> s1(s.begin(), s.end());
    set<int, greater<int>>::iterator it;
    cout << "\nThe set s1 is : \n";
    for (it = s1.begin(); it != s1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // remove all element in the set1 upto 22
    s1.erase(s1.begin(), s1.find(22));
    cout << "\nThe set s1 is : \n";
    for (it = s1.begin(); it != s1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // lower_bound & upper_bound in s1 set
    cout << "s1.lower_bound(22) : \n"
         << *s1.lower_bound(22) << endl;
    cout << "s1.upper_bound(22) : \n"
         << *s1.upper_bound(22) << endl;

    // lower_bound & upper_bound in s set
    cout << "s.lower_bound(13) : \n"
         << *s.lower_bound(13) << endl;
    cout << "s.upper_bound(13) : \n"
         << *s.upper_bound(13) << endl;

    return 0;
}