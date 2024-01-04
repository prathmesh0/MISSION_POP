#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//Brute force
// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int maxi = 0;
//         int n = s.size();
//         for(int i = 0; i < n; i++) {
//             int count = 0;
//             int j = i;
//             while(j < n) {
//                 if(s[j] != s[i]) {
//                     count++;
//                 }
//                 if(count > k) {
//                     break;
//                 }
//                 j++;
//             }
//             maxi = max(maxi, j - i);
//         }
//         return maxi;
//     }
// };

//Optimal
class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0;
        int j = 0;
        int ans = 0;
        int n = s.length();
        unordered_map<int,int>mpp;
        int maxC = 0;
        while(j<n){
            mpp[s[j]]++;
            //calculate maximum frequency from map
            maxC = max(maxC, mpp[s[j]]);
            int curr_len = j-i+1;
            if(curr_len - maxC > k){
                mpp[s[i]]--;
                i++;
            }
           curr_len = j-i+1;// just in case i is changed
            ans = max(ans, curr_len);
            j++;
        }
        return ans;
    }
};

// Input function
pair<string, int> takeInput() {
    string s;
    int k;
    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter the value of k: ";
    cin >> k;
    return {s, k};
}

int main() {
    Solution solution;
    auto input = takeInput();
    int result = solution.characterReplacement(input.first, input.second);
    cout << "Maximum length after replacing characters: " << result << endl;

    return 0;
}
