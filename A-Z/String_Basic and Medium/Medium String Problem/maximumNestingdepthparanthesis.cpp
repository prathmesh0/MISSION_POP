#include<bits/stdc++.h>
using namespace std;


//using stack
// int maxDepth(string s) {
//         int max_count = 0;
//         stack<char>st;
//         for(int i=0; i<s.size(); i++){
//             if(s[i] == '('){
//                 st.push('(');
//             }
//             else if(s[i] == ')'){
//                 int size = st.size();
//                 max_count = max(max_count, size);
//                 st.pop();
//             }
//         }
//         return max_count;

//     }

    //optimal approach
    int maxDepth(string s) {
        int max = 0;
        int curr_max =0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                curr_max++;
                if(curr_max>max){
                    max = curr_max;
                }
            }
            else if(s[i] == ')'){
                if(curr_max >0){
                    curr_max--;
                }
                else{
                    return -1;
                }
            }
        }
        if(curr_max != 0 ){
            return -1;
        }
        return max;
    }

int main(){
    string s = "(1)+((2))+(((3)))";
    cout<<maxDepth(s)<<endl;
    return 0;
}