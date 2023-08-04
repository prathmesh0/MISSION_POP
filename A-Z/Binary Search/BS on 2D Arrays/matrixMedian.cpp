#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Brute force

// int Findmedian(vector<vector<int>>& arr) {
//     int row = arr.size();
//     int col = arr[0].size();
//     vector<int> medianArray;
//     int ind = 0;
//     for (int i = 0; i < row; i++) {
//         for (int j = 0; j < col; j++) {
//             medianArray.push_back(arr[i][j]);
//             ind++;
//         }
//     }
//     sort(medianArray.begin(), medianArray.end());

//     return medianArray[(row * col) / 2];
// }

// Optimal Approach
int countSmallerThanMid(vector<int> &row, int k)
{
    int l = 0, h = row.size() - 1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (row[mid] <= k)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return l;
}
int Findmedian(vector<vector<int>> &arr)
{
    int low = 0, high = 1e9;
    int n= arr.size();
    int m = arr[0].size();

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += countSmallerThanMid(arr[i], mid);
        }
        if (cnt <= (n * m) / 2)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    vector<vector<int>> arr = {{1, 3, 8},
                               {2, 3, 4},
                               {1, 2, 5}};
    int ans = Findmedian(arr);

    cout << "The median of the row-wise sorted matrix is: " << ans << endl;
    return 0;
}
