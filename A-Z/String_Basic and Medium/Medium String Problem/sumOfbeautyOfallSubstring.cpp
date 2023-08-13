class Solution {
    //brute force
public:
    int beautySum(string s) {
        int ans =0;
        int n = s.length();
        for(int i =0; i<n; i++){
            unordered_map<char,int>mp;
            for(int j = i; j<n; j++){
                mp[s[j]]++;
                int  mini_freq = INT_MAX, maxi_freq = INT_MIN;
                for(auto it: mp){
                    mini_freq = min(it.second, mini_freq);
                    maxi_freq = max(it.second,maxi_freq);
                }
                ans +=  maxi_freq -mini_freq;
            }
        }
        return ans;
    }

    //optimal approach
public:
    int beautySum(string s) {
        int ans =0;
        int n = s.length();
        for(int i =0; i<n; i++){
            unordered_map<char,int>mp;
            multiset<int> st;
            for(int j = i; j<n; j++){
                if(mp.find(s[j]) != mp.end())
                st.erase(st.find(mp[s[j]]));
                mp[s[j]]++;
                st.insert(mp[s[j]]);
                ans += (*st.rbegin() - *st.begin());
                
            }
        }
        return ans;
    }
};