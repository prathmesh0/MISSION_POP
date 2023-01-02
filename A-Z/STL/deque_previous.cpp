#include <iostream>
#include <deque>
using namespace std;

void showdq(deque<int> k)
{
    deque<int>::iterator it;
    for (it = k.begin(); it != k.end(); ++it)
    {
        cout << "\t" << *it;
    }
    cout << endl;
}

int main()
{
    deque<int> d;
    d.push_back(12);
    d.push_back(16);
    d.push_back(10);
    d.push_front(1);
    d.push_front(2);
    d.push_front(23);
    d.push_front(26);
    showdq(d);
    d.pop_back();
    d.pop_front();
    showdq(d);

    cout << "size of dq( number of element ): " << d.size() << endl;
    cout << " maximum size of dq: " << d.max_size() << endl;

    cout << "front element of dq =" << d.front() << endl;
    cout << "last element of dq =" << d.back() << endl;
    cout << "element at position 2 =" << d.at(2) << endl;

    // error throw
    // cout<<"find the element at given position ="<<d.find(d.begin(),10)<<endl;

    cout << "resize the dq... " << endl;
    d.resize(3);
    cout << "size of dq( number of element ) after resize : " << d.size() << endl;
    showdq(d);

    // erase
    deque<int>::iterator i;
    i = d.begin() + 1;
    d.erase(i);
    showdq(d);

    d.clear();
    cout << "size of dq( number of element ) after clear : " << d.size() << endl;
    return 0;
}