#include <bits/stdc++.h>
using namespace std;

// Bruteforce Approach
// vector<int> peakElementII(vector<vector<int>> &matrix)
// {
//     int m = matrix.size();
//     int n = matrix[0].size();

//     vector<int> ans;

//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             bool flag = true;

//             // check for top
//             if (i > 0 && matrix[i][j] < matrix[i - 1][j])
//             {
//                 flag = false;
//             }

//             // check for bottom
//             if (i < n - 1 && matrix[i][j] < matrix[i + 1][j])
//             {
//                 flag = false;
//             }

//             // check for left
//             if (j > 0 && matrix[i][j] < matrix[i][j - 1])
//             {
//                 flag = false;
//             }

//             // chcek  for right
//             if (j < m - 1 && matrix[i][j] < matrix[i][j + 1])
//             {
//                 flag = false;
//             }
//             if (flag)
//             {
//                 return {i, j};
//             }
//         }
//     }
//     return {-1, -1};
// }

// Optimal Approach
vector<int> peakElementII(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int lo = 0; 
    int hi = m - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        int max_row = 0;
        for (int i = 0; i < n; ++i)
        {
            if (matrix[max_row][mid] < matrix[i][mid])
                max_row = i;
        }
        if ((mid == 0 || matrix[max_row][mid] > matrix[max_row][mid - 1]) &&
            (mid == m - 1 || matrix[max_row][mid] > matrix[max_row][mid + 1]))
            return {max_row, mid};
        else if (mid > 0 && matrix[max_row][mid - 1] > matrix[max_row][mid])
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return {-1, -1};
}

int main()
{
    vector<vector<int>> matrix = {{1, 4}, {3, 2}};
    vector<int> ans = peakElementII(matrix);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}