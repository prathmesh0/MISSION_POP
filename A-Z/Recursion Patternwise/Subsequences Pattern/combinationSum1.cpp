#include<bits/stdc++.h>
using namespace std;

void helper(vector<int>& candidates, int target,int ind, vector<int> &ds, vector<vector<int>> &ans){
        //BC
        if(ind == candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        //Include
        if(candidates[ind] <= target){
        ds.push_back(candidates[ind]);
        helper(candidates, target-candidates[ind], ind, ds, ans);
        ds.pop_back();
        }
        //Exclude
        helper(candidates, target, ind+1, ds, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>>ans;
         vector<int>ds;
         helper(candidates, target, 0, ds, ans);
         return ans;
    }

    #include <iostream>
#include <vector>

class Solution {
public:
    // ... (helper and combinationSum functions remain the same)
};

int main() {
   
    vector<int> candidates;
    int target;

    cout << "Enter the number of candidates: ";
    int numCandidates;
    cin >> numCandidates;

    cout << "Enter the candidates: ";
    for (int i = 0; i < numCandidates; i++) {
        int candidate;
        cin >> candidate;
        candidates.push_back(candidate);
    }

    cout << "Enter the target sum: ";
    cin >> target;

    vector<vector<int>> result = combinationSum(candidates, target);

    cout << "Combinations that sum up to " << target << ":" << endl;
    for (const vector<int>& combination : result) {
        cout << "[";
        for (int num : combination) {
            cout << num << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
