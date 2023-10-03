
#include <bits/stdc++.h>
using namespace std;

void insertinStack(stack<int> &st, int temp)
{
    if (st.size() == 0)
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
void reverseStack(stack<int> &stack)
{
    // Base Case
    if (stack.size() == 1)
    {
        return;
    }
    int temp = stack.top();
    stack.pop();
    reverseStack(stack);
    insertinStack(stack, temp);
    return;
}
int main()
{
    stack<int> st;

    // Input: Push elements onto the stack
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        st.push(element);
    }

    // Reverse the stack
    reverseStack(st);

    // Output: Print the reversed stack
    cout << "Reversed Stack:" << endl;
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
