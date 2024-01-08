#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// class Solution {
// public:
//     bool isPresent(string s){
//         bool hasA = false, hasB = false, hasC = false;
//         for(auto ch: s){
//             if(ch == 'a') hasA = true;
//             if(ch == 'b') hasB = true;
//             if(ch == 'c') hasC = true;
//         }
//         return (hasA && hasB && hasC);
//     }

//     int numberOfSubstrings(string s) {
//         int n = s.length();
//         int count = 0;

//         for(int i = 0; i < n; i++){
//             for(int j = i + 2; j < n; j++){
//                 if(isPresent(s.substr(i, j - i + 1))){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int start = 0; 
        int count = 0;
        unordered_map<char, int>mpp;

        for(int end = 0; end < n; end++){
            mpp[s[end]]++;
            while(mpp['a'] >= 1 && mpp['b'] >= 1 && mpp['c'] >= 1){

                count +=  (n - end );
                if(mpp[s[start]] > 0){
                    mpp[s[start]]--;
                }
                start++;
            }
            

        }
        return count;
    }
};
string takeInput() {
    string input;
    cout << "Enter the string: ";
    getline(cin, input);
    return input;
}

int main() {
    Solution sol;
    string input = takeInput();
    int result = sol.numberOfSubstrings(input);
    cout << "Number of substrings containing all three characters: " << result << endl;
    return 0;
}
