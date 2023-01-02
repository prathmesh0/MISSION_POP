#include <iostream>
#include <list>
using namespace std;

void printList(list<int> li)
{
    list<int>::iterator it;

    for (it = li.begin(); it != li.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    list<int> li;
    li.push_back(10);
    li.push_back(20);
    li.push_front(30);
    li.push_front(40);
    li.push_front(50);
    cout << "the element in the list are :" << endl;
    printList(li);

    cout << "reversing the list :" << endl;
    li.reverse();
    printList(li);

    cout << "sorting list :" << endl;
    li.sort();
    printList(li);

    cout << "the size of the list " << li.size() << endl;
    cout << "the first element of the list " << li.front() << endl;
    cout << "deleting the first element " << endl;
    li.pop_front();
    printList(li);

    cout << "the last element of the list " << li.back() << endl;
    cout << "deleting the last element " << endl;
    li.pop_back();
    printList(li);

    return 0;
}