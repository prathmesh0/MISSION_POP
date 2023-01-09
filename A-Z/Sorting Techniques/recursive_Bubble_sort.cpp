#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n)
{
    // base case
    if (n == 1)
        return;
    int count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
            count++;
        }
    }
    // Check if any recursion happens or not
    // If any recursion is not happen then return
    if (count == 0)
        return;

    // Largest element is fixed,
    // recur for remaining array
    BubbleSort(arr, n - 1);
}

int main()
{
    int arr[1000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    BubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}