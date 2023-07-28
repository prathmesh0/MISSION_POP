#include <bits/stdc++.h>
using namespace std;

int countStudent(vector<int> &arr, int pages)
{
    int students = 1;
    int pagesStudent = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] + pagesStudent <= pages)
        {
            pagesStudent += arr[i];
        }
        else
        {
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

//Brute force approach
// int findPages(vector<int> &arr, int n, int m)
// {
//     if (m > n)
//         return -1;
//     int maxi = INT_MIN, sum = 0;
//     for (auto it : arr)
//     {
//         sum += it;
//         maxi = max(maxi, it);
//     }
//     for (int i = maxi; i <= sum; i++)
//     {
//         if (countStudent(arr, i) == m)
//         {
//             return i;
//         }
//     }
//     return maxi;
// }

//Optimal approach
int findPages(vector<int> &arr, int n, int m)
{
    if (m > n)
        return -1;
    int maxi = INT_MIN, sum = 0;
    for (auto it : arr)
    {
        sum += it;
        maxi = max(maxi, it);
    }
    
    int low =maxi, high = sum;
    while (low<= high)
    {
        int mid = low+(high-low)/2;
        if(countStudent(arr,mid) > m){
            low =mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
    
}

int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = findPages(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}