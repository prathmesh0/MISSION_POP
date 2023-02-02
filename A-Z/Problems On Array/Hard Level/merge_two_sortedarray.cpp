#include <bits/stdc++.h>
using namespace std;
/*
//brute-force approach
void merge(int arr1[], int arr2[], int n, int m)
{
    int arr3[n + m];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        arr3[k++] = arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        arr3[k++] = arr2[i];
    }

    sort(arr3, arr3 + m + n);
    k = 0;
    for (int i = 0; i < n; i++)
    {
        arr1[i] = arr3[k++];
    }
    for (int i = 0; i < m; i++)
    {
        arr2[i] = arr3[k++];
    }
}

void merge(int arr1[], int arr2[], int n, int m)
{
    int i, k;
    // take first element from arr1
    // compare it with first element of arr2
    // if condition match then swap
    for (i = 0; i < n; i++)
    {
        if (arr1[i] > arr2[0])
        {
            int temp = arr1[i];
            arr1[i] = arr2[0];
            arr2[0] = temp;
        }
        // sort second array
        // insertion sort
        int first = arr2[0];
        for (k = 1; k < m && arr2[k] < first; k++)
        {
            arr2[k - 1] = arr2[k];
        }
        arr2[k - 1] = first;
    }
}
*/

void merge(int arr1[], int arr2[], int n, int m)
{
    int gap = ceil((float)(n + m) / 2);
    while (gap > 0)
    {
        int i = 0;
        int j = gap;
        while (j < (n + m))
        {

            if (j < n && arr1[i] > arr1[j])
            {
                swap(arr1[i], arr1[j]);
            }
            else if (j >= n && i < n && arr1[i] > arr2[j - n])
            {
                swap(arr1[i], arr2[j - n]);
            }
            else if (j >= n && i >= n && arr2[i - n] > arr2[j - n])
            {
                swap(arr2[i - n], arr2[j - n]);
            }
            j++;
            i++;
        }
        if (gap == 1)
            gap = 0;
        else
        {
            gap = ceil((float)gap / 2);
        }
    }
}
int main()
{
    int arr1[] = {1, 4, 7, 8, 10};
    int arr2[] = {2, 3, 9};
    cout << "Before merge:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    merge(arr1, arr2, 5, 3);
    cout << "After merge:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << arr2[i] << " ";
    }
    return 0;
}