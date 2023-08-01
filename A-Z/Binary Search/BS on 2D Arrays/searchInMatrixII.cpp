#include <bits/stdc++.h>
using namespace std;

//Brute force Approach
// bool searchInMatrixII(vector<vector<int>> &arr, int target)
// {
//     int n = arr.size();
//     int m = arr[0].size();
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (arr[i][j] == target)
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

//Optimal Approach
bool searchInMatrixII(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0;
    int col = m - 1;

    while (row < n && col >= 0)
    {
        if (matrix[row][col] == target)
        {
            return true;
        }
        else if (matrix[row][col] < target)
        {
            row++;
        }
        else
        {
            col--;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> arr = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target = 5;
    bool ans = searchInMatrixII(arr, target);
    if (ans)
    {
        cout << "target element is present" << endl;
    }
    else
    {
        cout << "target element is not present" << endl;
    }

    return 0;
}