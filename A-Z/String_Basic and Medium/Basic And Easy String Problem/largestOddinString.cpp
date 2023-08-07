#include <iostream>
#include <string>
using namespace std;

//Brute force approach
// bool is_odd_integer(string s) {
//     return stoi(s) % 2 != 0;
// }

// string largest_odd_substring(string num) {
//     int n = num.length();
//     string largest_odd = "";

//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j <= n; j++) {
//             string substring = num.substr(i, j - i);
//             if (is_odd_integer(substring) && (largest_odd == "" || stoi(substring) > stoi(largest_odd))) {
//                 largest_odd = substring;
//             }
//         }
//     }

//     return largest_odd;
// }


//Optimal Approach
string largest_odd_substring(string num) {
        int n = num.length();
        for(int i = n-1; i>= 0; i--){
            if(num[i] % 2){
                string s1 = num.substr(0, i+1);
                return s1;
            }
        }
        return "";
    }
int main() {
    string num = "123456789";
    cout << largest_odd_substring(num) << endl;  // Output: "789"

    return 0;
}
