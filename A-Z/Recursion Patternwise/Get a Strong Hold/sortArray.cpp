#include <bits/stdc++.h>
using namespace std;

void insertElement(vector<int> &v, int temp)
{
    // BC
    if (v.size() == 0 || v[v.size() - 1] <= temp)
    {
        v.push_back(temp);
        return;
    }
    int val = v[v.size() - 1];
    v.pop_back();
    insertElement(v, temp);
    v.push_back(val);
    return;
}

void sortVector(vector<int> &v)
{
    // BC
    if (v.size() == 1)
    {
        return;
    }
    int temp = v[v.size() - 1];
    v.pop_back();
    sortVector(v);
    insertElement(v, temp);
    return;
}
int main()
{
    vector<int> v = {2, 4, 5, 1, 0};
    sortVector(v);
    for (auto it : v)
    {
        cout << it << " ";
    }
    return 0;
}