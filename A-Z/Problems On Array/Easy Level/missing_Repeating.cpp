#include <iostream>
#include <vector>
using namespace std;

// leetcode missimg no.
int MissingNumber(int arr[], int n)
{
    int sum = 0;
    int total = (n * (n + 1)) / 2;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return total - sum;
}
vector<int> MissingAndRepeating(int arr[], int n)
{
    vector<int> temp(n + 1, 0);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        temp[arr[i]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (temp[i] == 0 || temp[i] > 1)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

int main()
{
    int n;
    int arr[10000];
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    v = MissingAndRepeating(arr, n);
    int ans = MissingNumber(arr, n);

    for (auto it : v)
    {
        cout << it << " ";
    }

    cout << endl;
    cout << "Missing Number :" << ans;

    return 0;
}