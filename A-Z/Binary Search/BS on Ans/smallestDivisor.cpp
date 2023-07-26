#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool isPossible(vector<int> &arr, int limit, int divisor){
    int sum = 0;
    for(int i = 0; i<arr.size(); i++){
        sum += ceil(((double)arr[i])/((double)divisor));
    }
    if(sum<= limit) return true;
    return false;
}
//BruteForce approach
// int smallestDivisor(vector<int> &arr, int limit)
// {
//     int n = arr.size();
//     int maxi = INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         maxi = max(maxi, arr[i]);
//     }
//     for (int i = 1; i < maxi; i++)
//     {
//         if(isPossible(arr, limit, i)){
//             return i;
//         }
//     }
//     return -1;
// }

//Optimal approach
int smallestDivisor(vector<int> &nums, int threshold)
{
    int n = nums.size();
        if(n>threshold) return -1;
        int maxi =INT_MIN;
        int ans = -1;
        for(auto it: nums){
            maxi = max(maxi, it);
        }
        int low = 1, high = maxi;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(isPossible(nums, threshold, mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    int ans = smallestDivisor(arr, limit);
    cout << "The minimum divisor is: " << ans << "\n";
    return 0;
}