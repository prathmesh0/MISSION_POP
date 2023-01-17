#include <iostream>
#include <vector>
using namespace std;

bool Search2D(vector<vector<int>> &arr, int target)
{
    int row = arr.size();
    int cols = arr[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == target)
                return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> arr;
    arr = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    bool ans = Search2D(arr, 10);
    if (ans)
        cout << "element  is present" << endl;
    else
        cout << "element  is not present" << endl;

    return 0;
}