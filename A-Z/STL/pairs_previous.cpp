#include <iostream>
using namespace std;

int main()
{
    pair<int, int> p1; // declaration of pairs
    p1.first = 12;
    p1.second = 132;
    cout << p1.first << endl;
    cout << p1.second << endl;

    // initialization
    pair<string, int> pop("prathmesh", 12);
    cout << pop.first << endl;
    cout << pop.second << endl;

    // copy pair
    pair<string, int> st(pop);
    cout << st.first << endl;
    cout << st.second << endl;

    // using make_pair templet function
    pair<double, char> jow;
    jow = make_pair(88.6, 'p');
    cout << jow.first << endl;
    cout << jow.second << endl;

    // swapping pairs
    pair<string, int> m("prathmesh", 100);
    pair<string, int> n("parab", 200);
    cout << "before swapping :" << endl;
    cout << m.first << " " << m.second << endl;
    cout << n.first << " " << n.second << endl;

    m.swap(n);
    cout << "after swapping :" << endl;
    cout << m.first << " " << m.second << endl;
    cout << n.first << " " << n.second << endl;
    return 0;
}