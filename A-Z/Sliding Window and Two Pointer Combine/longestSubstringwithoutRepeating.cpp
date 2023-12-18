#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

//brute force 
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.length();
//         int maxLength = INT_MIN;
//         for(int i = 0; i < n; i++) {
//             unordered_set<char> st;
//             for(int j = i; j < n; j++) {
//                 if(st.find(s[j]) != st.end()) {
//                     maxLength = max(maxLength, j - i);
//                     break;
//                 }
//                 st.insert(s[j]);
//             }
//         }
//         return maxLength;
//     }
// };

//better approach
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         if(s.length() == 0){
//             return 0;
//         }
//         unordered_set<char>st;
//         int maxLength =INT_MIN;
//         int l = 0;
//         for(int r = 0; r<s.size(); r++){
//             //if the char is present in the set
//             if(st.find(s[r]) != st.end()){
//                 while(l < r && st.find(s[r]) != st.end()){
//                     st.erase(s[l]);
//                     l++;
//                 }
//             }
//             //insert the char
//             st.insert(s[r]);
//             maxLength = max(maxLength, r-l+1);
//         }
//         return maxLength;
//     }
// };

//Optimal approach
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0){
            return 0;
        }
        int maxLength = INT_MIN;
        int l = 0, r = 0;
        int n = s.length();
        vector<int>mpp(256, -1);
        while(r < n){
            //if element is presernt
            if(mpp[s[r]] != -1){
                l = max(mpp[s[r]] + 1, l);
            }
            mpp[s[r]] = r;
            maxLength = max(maxLength, r - l + 1);
            r++;
        }
        return maxLength;
    }
};
// Input function
string takeInput() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    return input;
}

int main() {
    Solution sol;
    string input = takeInput();
    int result = sol.lengthOfLongestSubstring(input);
    cout << "Length of the longest substring without repeating characters: " << result << endl;

    return 0;
}
