#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    /*
    int n;
    int arr[1000];
    cin>>n;
    //4,3,3,2,5
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    //precomputation
    int hashMap[13] = {0};
    for(int i = 0; i<n; i++){
        hashMap[arr[i]] += 1;
    }

    //hash or fetching
    int q;
    cin>>q;
    while (q--)
    {
        int num;
        cin>>num;
        cout<<hashMap[num]<<endl;
    }


    string s;
    cin >> s;

    int Hashh[26];
    for (int i = 0; i < s.size(); i++)
    {
        Hashh[s[i] - 'a']++;
    }
    int q;
    cin>>q;
    while(q--){
        char ch;
        cin>>ch;
        cout<<Hashh[ch-'a'];
    }
    */
// map store all key in sorted ordered
// time complexity storing and fetching in map takes log(n)
// unordered map  stores all  key in random fashion
// in unordered map for storing and fetching data need O(1) time complexity but in worst case it will take O(n) time
// complexity and this happens rarely

    int m;
    int arr[10000];
    cin>> m;
    //4,4,3,3,5
    for(int i = 0; i<m; i++){
        cin>>arr[i];
    }
    map<int,int>mpp;
    for(int i = 0; i<m; i++){
        mpp[arr[i]]++;
    }
    //elements with the mapping
    for(auto it:mpp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    
    return 0;
}