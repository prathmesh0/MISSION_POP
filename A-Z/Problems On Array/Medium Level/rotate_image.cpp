#include <iostream>
#include <vector>
using namespace std;

// brute- force
vector<vector<int>> rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> rotated_matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rotated_matrix[j][n - i - 1] = matrix[i][j];
        }
    }
    return rotated_matrix;
}

// optimal approach
/*void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // transpose the give matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // reverse each row
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
*/

int main()
{
    vector<vector<int>> arr;
    arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> rotated = rotate(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < rotated.size(); i++)
    {
        for (int j = 0; j < rotated[0].size(); j++)
        {
            cout << rotated[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}