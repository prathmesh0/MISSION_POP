#include<bits/stdc++.h>
using namespace std;
//brute force approach
string frequencySort(string s) {
        unordered_map<char, int> mpp;
        for(auto it:s){
            mpp[it]++;
        }
        priority_queue<pair<int, char>>pq;
        for(auto it: mpp){
            pq.push({it.second, it.first});
        }
        string t ="";
        while(!pq.empty()){
            t += string(pq.top().first , pq.top().second);
            pq.pop();
        }
        return t;
    }

int main(){
    string s= "treee";
    string ans = frequencySort(s);
    cout<<ans<<endl;

    return 0;
}