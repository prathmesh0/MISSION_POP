#include <iostream>
using namespace std;

/*
//iterative approach
int BinarySearch(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return -1;
}
*/

// recursive approach
int BinarySearch(int arr[], int s, int e, int key)
{
    // base case
    if (s > e)
        return -1;
    int mid = s + (e - s) / 2;
    if (key == arr[mid])
    {
        return mid;
    }
    else if (key > arr[mid])
    {
        BinarySearch(arr, mid + 1, e, key);
    }
    else
    {
        BinarySearch(arr, s, mid - 1, key);
    }
}

int Position(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;

    return (BinarySearch(arr, s, e, key));
}

int main()
{
    int arr[1000];
    int n, key;
    cin >> n;
    cin >> key;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int index = Position(arr, n, key);
    cout << "Position of the given key element is " << index << endl;

    return 0;
}