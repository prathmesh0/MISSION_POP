#include <iostream>
#include <vector>
using namespace std;

// brute-force apprach
/*
void Setmatrix(vector<vector<int>> &v)
{
    int row = v.size();
    int col = v[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (v[i][j] == 0)
            {
                int ind = i - 1;
                while (ind >= 0)
                {
                    if (v[ind][j] != 0)
                    {
                        v[ind][j] = -1;
                    }
                    ind--;
                }
                ind = i + 1;
                while (ind < row)
                {
                    if (v[ind][j] != 0)
                    {
                        v[ind][j] = -1;
                    }
                    ind++;
                }

                ind = j - 1;
                while (ind >= 0)
                {
                    if (v[i][ind] != 0)
                    {
                        v[i][ind] = -1;
                    }
                    ind--;
                }
                ind = j + 1;
                while (ind < col)
                {
                    if (v[i][ind] != 0)
                    {
                        v[i][ind] = -1;
                    }
                    ind++;
                }
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (v[i][j] <= 0)
            {
                v[i][j] = 0;
            }
        }
    }
}

void Setmatrix(vector<vector<int>> &v)
{
    int rows = v.size(), cols = v[0].size();
    vector<int> dummy1(rows, -1);
    vector<int> dummy2(cols, -1);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (v[i][j] == 0)
            {
                dummy1[i] = 0;
                dummy2[j] = 0;
            }
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (dummy1[i] == 0 || dummy2[j] == 0)
            {
                v[i][j] = 0;
            }
        }
    }
}
*/
// optimal approach
void Setmatrix(vector<vector<int>> &matrix)
{
    int rows = matrix.size(), cols = matrix[0].size();
    int col0 = 1;
    for (int i = 0; i < rows; i++)
    {
        // check if the 0th col contain 0 or not
        if (matrix[i][0] == 0)
        {
            col0 = 0;
        }
        for (int j = 1; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    // traversing in the reverse direction and
    // checking if the row or col has 0 or not
    // and setting values of matrix accordingly.

    for (int i = rows - 1; i >= 0; i--)
    {
        for (int j = cols - 1; j >= 1; j--)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
        if (col0 == 0)
        {
            matrix[i][0] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> v;
    v = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}, {1, 0, 4, 5}};
    Setmatrix(v);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}