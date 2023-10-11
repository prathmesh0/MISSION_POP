#include <bits/stdc++.h>
using namespace std;

//brute force approach
// void helper(int ind, int target, vector<int> &candidates, vector<int> &ds, set<vector<int>> &ans)
// {
//     if (ind == candidates.size())
//     {
//         if (target == 0)
//         {
//             ans.insert(ds);
//         }
//         return;
//     }
//     ds.push_back(candidates[ind]);
//     helper(ind + 1, target - candidates[ind], candidates, ds, ans);
//     ds.pop_back();
//     helper(ind + 1, target, candidates, ds, ans);
// }

// vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
// {
//     sort(candidates.begin(), candidates.end());
//     set<vector<int>> ans;
//     vector<vector<int>> final_ans;
//     vector<int> ds;
//     helper(0, target, candidates, ds, ans);
//     for (const auto &it : ans)
//     {
//         final_ans.push_back(it);
//     }
//     return final_ans;
// }

//optimal approach
void findCombination(int ind, int target, vector<int>& arr, vector<vector<int>> &ans,  vector<int> &ds  ){
        if(target==0){
            ans.push_back(ds);
            return ;
        }
        for(int i= ind; i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1])
    continue;
            if(arr[i]>target)
                break;
            ds.push_back(arr[i]);
            findCombination(i+1, target-arr[i], arr, ans, ds);
            ds.pop_back();
            
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> result = combinationSum2(candidates, target);

    for (const vector<int>& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
