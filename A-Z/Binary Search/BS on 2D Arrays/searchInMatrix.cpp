#include <bits/stdc++.h>
using namespace std;

// BruteForce Approach
//  bool searchInMatrix(vector<vector<int>> &arr,int target){
//      for(int i =0; i<arr.size(); i++){
//          for(int j = 0; j<arr[0].size(); j++){
//              if(arr[i][j] == target){
//                  return true;
//              }
//          }
//      }
//      return false;
//  }

// Better Approach
// bool searchInMatrix(vector<vector<int>> &arr, int target)
// {
//     int n = arr.size();
//     int m = arr[0].size();
//     int i = 0;
//     int j = m-1;

//     while (i < n && j >= 0)
//     {
//         if (arr[i][j] == target)
//             return true;
//         else if (arr[i][j] < target)
//         {
//             i++;
//         }
//         else
//         {
//             j--;
//         }
//     }
//     return false;
// }

//Optimal Approach

bool searchInMatrix(vector<vector<int>> &arr, int target)
{
    int n = arr.size();
    int m = arr[0].size();
    int low = 0, high = m*n-1;
    while (low<=high)
    {
        int mid = low+(high- low)/2;

        if(arr[mid/m][mid%m] == target){
            return true;
        }
        else if(arr[mid/m][mid%m] < target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return false;
    
}
int main()
{
    vector<vector<int>> arr = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 10;
    bool ans = searchInMatrix(arr, target);
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