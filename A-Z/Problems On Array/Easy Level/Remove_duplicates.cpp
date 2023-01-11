#include <iostream>
#include <set>
using namespace std;

/*
//brute force approach
int Remove_Duplicates(int arr[], int n)
{
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.emplace(arr[i]);
    }
    int k = st.size();
    int j = 0;
    for (auto it = st.begin(); it != st.end(); it++)
    {
        arr[j++] = *it;
    }
    return k;
}
*/

// optimal approach(using 2 pointers)
int remove_duplicate(int a[], int n)
{

    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (a[i] != a[j])
        {
            i++;
            a[i] = a[j];
        }
    }
    return i + 1;
}

int main()
{
    int n;
    int arr[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // int last = Remove_Duplicates(arr, n);
    int elements = remove_duplicate(arr, n);
    cout << elements << endl;
    for (int i = 0; i < elements; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}