#include<bits/stdc++.h>
using namespace std;

int countPainters(vector<int> &arr, int time){
    int n = arr.size();
    int painters = 1;
    long long boardsPainter = 0;
    for(int i = 0; i<arr.size(); i++){
        if(boardsPainter+arr[i] <= time){
            boardsPainter += arr[i];
        }
        else{
            painters++;
            boardsPainter = arr[i];
        }
    }
    return painters;
}

//Optimal Approach
int findLargestMinDistance(vector<int> &boards, int k)
{
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    
   
    while(low <= high){
        int mid = low+(high-low)/2;
        if(countPainters(boards, mid) <= k){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}


//Bruteforce Approach
// int findLargestMinDistance(vector<int> &boards, int k){
//     int sum = 0;
//     int maxi = INT_MIN;

//     for(auto it: boards){
//         sum += it;
//         maxi = max (maxi, it);
//     }

//     for(int i = maxi; i<=sum; i++){
//         if(countPainters(boards, i) <= k){
//             return i;
//         }
//     }
//     return maxi;
// }

int main(){
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;
    int ans = findLargestMinDistance(boards, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}