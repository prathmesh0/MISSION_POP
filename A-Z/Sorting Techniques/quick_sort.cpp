#include <iostream>
using namespace std;

int Partition(int arr[], int l, int r)
{
    int pivot = arr[l];
    int start = l;
    int end = r;

    while (start < end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }

        while (arr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[l], arr[end]);
    return end;
}

void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int loc = Partition(arr, l, r);
        quickSort(arr, l, loc - 1);
        quickSort(arr, loc + 1, r);
    }
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
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}