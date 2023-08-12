class Solution
{
    // brute force approach
    /*public:
    bool isPalindrome(string s){
        int i =0, j = s.size()-1;
        while(i<j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }

    public:
        string longestPalindrome(string s) {
            int n = s.size();
            if(n == 0) return "";
            if(n == 1) return s;

            string result = "";
            for(int i = 0; i<n-1; i++){
                for(int j = 1; j<=n-i; j++){
                    if(isPalindrome(s.substr(i,j))){
                        if(result.size() < j){
                            result = s.substr(i,j);
                        }
                    }
                }
            }
            return result;
        }*/

    // optimal approach

public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        int len = 1; // default length
        int start = 0, end = 0;
        for (int i = 0; i < n; i++)
        {

            // odd length
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                if ((r - l + 1) > len)
                {
                    len = r - l + 1;
                    start = l;
                    end = r;
                }
                l--;
                r++;
            }

            // even length
            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                if ((r - l + 1) > len)
                {
                    len = r - l + 1;
                    start = l;
                    end = r;
                }
                l--;
                r++;
            }
        }
        string ans = s.substr(start, end - start + 1);
        return ans;
    }
};
