#include <iostream>
#include <queue>
using namespace std;

void Printdeque(deque<int> dq)
{
    deque<int>::iterator it;
    for (it = dq.begin(); it != dq.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    deque<int> dq;
    dq.push_back(18);
    dq.push_back(4);
    dq.push_back(67);
    dq.push_front(54);
    dq.push_front(16);
    cout << "element in the dq " << endl;
    Printdeque(dq);

    cout << "size of the deque " << dq.size() << endl;

    cout << "The  first element in the deque " << dq.front() << endl;
    dq.pop_front();
    Printdeque(dq);

    cout << "The  last element in the deque " << dq.back() << endl;
    dq.pop_back();
    Printdeque(dq);
    return 0;
}