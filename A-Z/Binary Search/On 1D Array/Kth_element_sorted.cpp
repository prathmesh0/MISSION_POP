#include <iostream>
using namespace std;
/*
//brute force approach
int kthelement(int array1[], int array2[], int m, int n, int k)
{
    int p1 = 0, p2 = 0, counter = 0, answer = 0;

    while (p1 < m && p2 < n)
    {
        if (counter == k)
            break;
        else if (array1[p1] < array2[p2])
        {
            answer = array1[p1];
            ++p1;
        }
        else
        {
            answer = array2[p2];
            ++p2;
        }
        ++counter;
    }
    if (counter != k)
    {
        if (p1 != m - 1)
            answer = array1[k - counter];
        else
            answer = array2[k - counter];
    }
    return answer;
}
*/

// optimal approach
int kthelement(int row1[], int row2[], int m, int n, int k)
{

    if (m > n)
    {
        return kthelement(row2, row1, n, m, k);
    }
    int low = max(0, k - n), high = min(k, m);
    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = k - cut1;

        int l1 = cut1 == 0 ? INT_MIN : row1[cut1 - 1];
        int l2 = cut2 == 0 ? INT_MIN : row2[cut2 - 1];
        int r1 = cut1 == m ? INT_MAX : row1[cut1];
        int r2 = cut2 == n ? INT_MAX : row2[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if (l1 > r2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
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