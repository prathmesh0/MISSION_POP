#include <bits/stdc++.h>
using namespace std;

// Iterative approach
// int binarySearch(vector<int> &arr, int target)
// {
//     int low = 0;
//     int high = arr.size() - 1;
//     while (low <= high)
//     {
//         int mid = low + (high - low) / 2;
//         if (arr[mid] == target)
//         {
//             return mid;
//         }
//         else if (target > arr[mid])
//         {
//             low = mid + 1;
//         }
//         else
//         {
//             high = mid - 1;
//         }
//     }
//     return -1;
// }

// recursive approach
int binarySearch(vector<int> &arr,int low, int high, int target)
{

    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
    {
        return binarySearch(arr, mid + 1, high, target);
    }
    else
    {
        return binarySearch(arr, low, mid - 1, target);
    }
}

int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    int n = a.size();
    int ind = binarySearch(a, 0, n - 1, target);
    if (ind == -1)
        cout << "The target is not present." << endl;
    else
        cout << "The target is at index: "
             << ind << endl;
    return 0;
}