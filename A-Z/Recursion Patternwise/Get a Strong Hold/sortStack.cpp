#include <bits/stdc++.h>
using namespace std;

void insertinStack(stack<int> &st, int temp)
{
    if (st.size() == 0 || st.top() <= temp)
    {
        st.push(temp);
        return;
    }
    int val = st.top();
    st.pop();
    insertinStack(st, temp);
    st.push(val);
    return;
}
void sortStack(stack<int> &stack)
{
    if (stack.size() == 1)
    {
        return;
    }
    int temp = stack.top();
    stack.pop();
    sortStack(stack);
    insertinStack(stack, temp);
    return;
}

int main()
{
    stack<int> st;
    st.push(4);
    st.push(6);
    st.push(21);
    st.push(3);
    st.push(1);

    sortStack(st);

    // Print the sorted stack
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}