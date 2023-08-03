#include <bits/stdc++.h>
using namespace std;

// Bruteforce Approach
// int kthelement(int array1[], int array2[], int m, int n, int k)
// {
//     int p1 = 0;
//     int p2 = 0;
//     int count = 0;
//     int answer = 0;

//     while (p1 < m && p2 < n)
//     {
//         if (count == k)
//         {
//             break;
//         }
//         else if (array1[p1] < array2[p2])
//         {
//             answer = array1[p1];
//             ++p1;
//             ++count;
//         }
//         else
//         {
//             answer = array2[p2];
//             ++p2;
//             ++count;
//         }
//     }
//     if (count != k)
//     {
//         if (p1 != m - 1)
//             answer = array1[k - count];
//         else
//             answer = array2[k - count];
//     }
//     return answer;
// }

// Optimal Approach

int kthelement(int arr1[], int arr2[], int m, int n, int k)
{
    if (m > n)
    {
        return kthelement(arr2, arr1, n, m, k);
    }

    int low = max(0, k - m);
    int high = min(k, n);
    while (low <= high)
    {
        int cut1 = low + (high - low) / 2;
        int cut2 = k - cut1;

        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        int r1 = cut1 == n ? INT_MAX : arr1[cut1];
        int r2 = cut2 == m ? INT_MAX : arr2[cut2];

        if(l1<= r2 && l2<= r1){
            return (max(l1,l2));
        }
        else if(l1> r2){
            high = cut1-1;
        }
        else{
            low = cut1+1;
        }
    }
    return 1;
}

int main()
{
    int array1[] = {2, 3, 6, 7, 9};
    int array2[] = {1, 4, 8, 10};
    int m = sizeof(array1) / sizeof(array1[0]);
    int n = sizeof(array2) / sizeof(array2[0]);
    int k = 5;
    cout << "The element at the kth position in the final sorted array is "
         << kthelement(array1, array2, m, n, k);
    return 0;
}