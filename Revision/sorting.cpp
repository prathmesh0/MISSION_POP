#include <iostream>
#include <vector>
using namespace std;
// selection sort
// TC = O(n^2)
void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int mini = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }
        if (mini != i)
        {
            swap(arr[i], arr[mini]);
        }
    }
}

// bubble sort
// TC = O(n^2)-> in worst case
// TC = O(n)-> in best case-> sorted
void bubble_sort(int arr[], int n)
{
    int flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
        cout << " no." << endl;
    }
}
// insertion sort
// TC = O(n^2)-> in worst case
// TC = O(n)-> in best case-> sorted
void insertion_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

void merge(int arr[], int l, int mid, int r)
{
    int i = l;
    int j = mid + 1;
    int k = l;
    int temp[100000];
    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    if (i > mid)
    {
        while (j <= r)
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
    }

    for (int k = l; k <= r; k++)
    {
        arr[k] = temp[k];
    }
}
// Merge sort
void merge_sort(int arr[], int s, int e)
{
    if (s < e)
    {
        int mid = (s + e) / 2;
        merge_sort(arr, s, mid);
        merge_sort(arr, mid + 1, e);
        merge(arr, s, mid, e);
    }
}

// recursive Bubble sort
void bubbleRec_sort(int arr[], int n)
{
    // BC
    if (n == 1)
        return;
    int flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
            flag = 1;
        }
    }
    if (flag == 0)
        return;
    // RC
    bubbleRec_sort(arr, n - 1);
}

// recursive Insertion sort
void insertionRec_sort(int arr[], int i, int n)
{
    // BC
    if (i == n)
        return;

    int j = i;
    while (j > 0 && arr[j - 1] > arr[j])
    {
        int temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
        j--;
    }
    insertionRec_sort(arr, i + 1, n);
}

int partition(int arr[], int l, int r)
{
    int start = l;
    int end = r;
    int pivot = arr[l];

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

// Quick sort
void quick_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int loc = partition(arr, l, r);
        quick_sort(arr, l, loc-1);
        quick_sort(arr, loc + 1, r);
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before selection sort:"
         << "\n";
    printArray(arr, n);
    cout << "\n";
    // selection_sort(arr, n);
    // printArray(arr, n);
    // bubble_sort(arr, n);
    // printArray(arr, n);
    // insertion_sort(arr, n);
    // printArray(arr, n);
    // merge_sort(arr, 0, n - 1);
    // printArray(arr, n);
    // bubbleRec_sort(arr, n);
    // printArray(arr, n);
    // insertionRec_sort(arr,0, n);
    // printArray(arr, n);
    quick_sort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}