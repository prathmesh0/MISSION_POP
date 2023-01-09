#include <iostream>
using namespace std;

void Merge(int arr[], int l, int mid, int r)
{
    int i = l;       // starting index of left part of array
    int j = mid + 1; // starting index of right part of array
    int k = l;       // index used to transfer the elements in temp array
    int temp[100000];

    while (i <= mid && j <= r) // both array sublist are in bound
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    if (i > mid) // left sublist is exceed the size
    {
        while (j <= r)
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    else // right sublist is exceed the size
    {
        while (i <= mid)
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
    }

    // copy temp array into original
    for (int k = l; k <= r; k++)
    {
        arr[k] = temp[k];
    }
}

void MergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;      // finding middle element
        MergeSort(arr, l, mid);     // left half
        MergeSort(arr, mid + 1, r); // right half
        Merge(arr, l, mid, r);      // merge 2 halves
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
    MergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}