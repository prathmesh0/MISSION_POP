#include <iostream>
#include <list>
using namespace std;
void showlist(list<int> g)
{
    list<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << "\t" << *it;
    cout << "\t";
    cout << endl;
}

int main()
{
    list<int> l1, l2;
    for (int i = 1; i <= 5; i++)
    {
        l1.push_back(i * 2);
        l2.push_front(i * 3);
    }
    showlist(l1);
    cout << endl;
    showlist(l2);
    cout << endl;

    cout << "first element of in list1 = " << l1.front() << endl;
    cout << "last element of in list1 = " << l1.back() << endl;

    // remove 1st elment of list 1
    cout << "remove 1st element of list1 :" << endl;
    l1.pop_front();
    showlist(l1);

    // remove last elment of list 1
    cout << "remove last element of list1 :" << endl;
    l1.pop_back();
    showlist(l1);

    // rbegin() rend()

    list<int> pop = {1, 2, 3, 4, 5, 6, 7};
    cout << "list reverse :" << endl;
    for (auto i = pop.rbegin(); i != pop.rend(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
    cout << "list cbegin() and cend() :" << endl;
    for (auto it = pop.cbegin(); it != pop.cend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "list crbegin() and crend() :" << endl;
    for (auto it = pop.crbegin(); it != pop.crend(); ++it)
    {
        cout << *it << " ";
    }
    return 0;
}