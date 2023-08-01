#include <bits/stdc++.h>
using namespace std;

//Bruteforce Approach
// vector<int> rowWithMax1s(vector<vector<int>> &arr)
// {
//     vector<int> ans;
//     int n = arr.size();
//     int m = arr[0].size();
//     int rowIndex = -1;
//     int maxCount = 0;

//     for (int i = 0; i < n; i++)
//     {
//         int count = 0;
//         for(int j = 0; j<m; j++){
//             if(arr[i][j] == 1){
//                 count++;
//             }
//         }
//         if(count> maxCount){
//             maxCount = count;
//             rowIndex = i;
//         }
//     }
//     ans.push_back(rowIndex);
//     ans.push_back(maxCount);
//     return ans;
// }

//Better Approach
 int oneInRow(vector<int> &row, int cols){
        //Check for only one column
        if (cols == 1)
        return (row[0] == 1);

        int n = row.size();
        int low = 0, high = n-1;
        sort(row.begin(), row.end());

        while(low<=high){
            int mid = low+(high-low)/2;
            if(row[mid] == 1){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return (cols-low);
    }
    vector<int> rowWithMax1s(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0]. size();
        int maxiOne = 0;
        int ind = 0;
        vector<int>ans;
         
        for(int i=0;i<n; i++){
            int count = oneInRow(mat[i], m);

            if(count> maxiOne){
            maxiOne = count;
            ind = i;
        }
        }
        
        ans.push_back(ind);
        ans.push_back(maxiOne);
        return ans;
    }

int main()
{
    vector<vector<int>> mat = {{0, 0, 0, 1},
                               {0, 1, 1, 1},
                               {1, 1, 1, 1},
                               {0, 0, 0, 0}};

    vector<int> ans = rowWithMax1s(mat);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}