#include <iostream>
using namespace std;
bool arraySortedOrNot(int arr[], int n)
{

    if (n == 0 || n == 1)
        return true;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
                return false;
        }
    }
    return true;
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
    bool ans = arraySortedOrNot(arr, n);
    cout << ans;
    return 0;
}