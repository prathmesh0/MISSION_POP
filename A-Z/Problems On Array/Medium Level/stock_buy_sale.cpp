#include <iostream>
using namespace std;

// Brute-force approach
/*
int Stock_buy_sale(int arr[], int n)
{
    int maxPro = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                maxPro = max(arr[j] - arr[i], maxPro);
            }
        }
    }
    return maxPro;
}
*/

// Optimal  approach
int Stock_buy_sale(int arr[], int n)
{
    int maxPro = 0;
    int minPrice = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        minPrice = min(minPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - minPrice);
    }
    return maxPro;
}

int main()
{
    int n;
    cin >> n;
    int arr[100000];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int profit = Stock_buy_sale(arr, n);
    cout << "maximum profit = " << profit << endl;
    return 0;
}