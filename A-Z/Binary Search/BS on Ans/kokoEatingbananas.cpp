#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int maxiInArray(vector<int> &arr){
    int maxi = INT_MIN;
    for(int i = 0; i<arr.size(); i++){
        if(arr[i]>  maxi){
            maxi = arr[i];
        }
    }
    return maxi;
}
long long totalHours(vector<int> &piles, int hourly){
    long long totalH = 0;
    for(int i = 0 ; i<piles.size(); i++){
        //TotalH += ceil((double)arr[i]/(double)huorly);
         totalH += (piles[i] + hourly - 1) / hourly;
    }
    return totalH;
}
//Breute force approach
// int (vector<int> &arr, int h)
// {
//     int n  = maxiInArray(arr);
//     for(int i = 1; i<=n; i++){
//         long long requireTime = totalHours(arr, i);
//         if(requireTime <= h) return i;
//     }
//     return n;
// }

int minimumRateToEatBananas(vector<int>& piles, int h) {
        int max = maxiInArray(piles);
        int low = 1,high = max;
        //int ans= max;
        while(low<=high){
            int mid = low+(high-low)/2;
            long long totalH = totalHours(piles, mid);
            if( totalH <= h){
                //ans  = mid;
                high = mid -1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }

int main(){
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minimumRateToEatBananas(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}