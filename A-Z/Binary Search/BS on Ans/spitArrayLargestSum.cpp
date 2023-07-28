#include <bits/stdc++.h>
using namespace std;

int countPartition(vector<int> &arr, int maxSum)
{
    int partition = 1;
    long long subArraySum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (subArraySum + arr[i] <= maxSum)
        {
            subArraySum += arr[i];
        }
        else
        {
            partition++;
            subArraySum = arr[i];
        }
    }
    return partition;
}

//Bruteforce approach
// int splitArray(vector<int> &arr, int k)
// {
//     int sum = 0, maxi = INT_MIN;
//     for (auto it : arr)
//     {
//         sum += it;
//         maxi = max(maxi, it);
//     }

//     for (int i = maxi; i <= sum; i++)
//     {
//         if (countPartition(arr, i) == k)
//         {
//             return i;
//         }
//     }
//     return maxi;
// }

//Optimal approach
int splitArray(vector<int>& arr, int k) {
        int sum=0, maxi = INT_MIN;
        for(auto  it: arr){
            sum+=it;
            maxi= max(maxi, it);
        }

        int low= maxi, high  = sum;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(countPartition(arr,mid)<= k){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
        
    }

int main()
{
    vector<int> a = {10, 20, 30, 40};
    int k = 2;
    int ans = splitArray(a, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}