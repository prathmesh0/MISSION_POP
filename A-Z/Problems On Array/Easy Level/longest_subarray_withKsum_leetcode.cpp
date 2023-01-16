#include <iostream>
using namespace std;

int subarrayKsum(int arr[], int n, int k)
{
    int ans = 0; // ans variable to store our count

    for (int i = 0; i < n; i++) // traverse from the array
    {
        int sum = arr[i]; // provide sum with arr[i]

        if (sum == k) // if element itself equal to k, then also increment count
            ans++;

        for (int j = i + 1; j < n; j++) // now moving forward,
        {
            sum += arr[j]; // add elements with sum

            if (sum == k) // if at any point they become equal to k
                ans++;    // increment answer
        }
    }

    return ans; // and at last, return answers
}

int main()
{
    int n, k;
    int arr[10000];
    cin >> n;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = subarrayKsum(arr, n, k);
    cout << "The number of subarrays " << ans << endl;
    return 0;
}