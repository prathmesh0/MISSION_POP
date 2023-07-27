#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int findDays(vector<int> &weights,int cap){
    int n  = weights.size();
    int load = 0, days =1;
    for(int i =0; i<n;i++){
        if(load+weights[i] > cap){
            days++;
            load = weights[i];
        }
        else{
            load += weights[i];
        }
    }
    return days;

}

//Brute force approach
// int  leastWeightCapacity(vector<int> &weights,int  d){
//     int n = weights.size();
//     int maxi = INT_MIN;
//     int sum = 0;
//     for(auto it:weights){
//         maxi = max(maxi,weights[it]);
//         sum += it;
//     }

//     for(int i = maxi; i<=sum; i++){
//         if(findDays(weights, i) <= d){
//             return i;
//         }
//     }
//     return -1;
// }

//Optimal approach
 int leastWeightCapacity(vector<int>& weights, int days) {
        int maxi =INT_MIN;
        int sum = 0;
        for(auto  it: weights){
            maxi = max(maxi, it);
            sum += it;
        }
        int low = maxi;
        int high = sum;
        while(low<= high){
            int mid = low+(high-low)/2;
            if(findDays(weights, mid) <= days){
                high= mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }

int main(){
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    int ans = leastWeightCapacity(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";
    return 0;
}