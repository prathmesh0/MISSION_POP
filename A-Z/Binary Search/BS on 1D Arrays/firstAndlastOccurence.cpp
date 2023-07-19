#include <iostream>
#include <vector>
using namespace std;

//Brute force
// vector<int> searchRange(vector<int> &nums, int target)
// {
//     int start = -1;
//     int end = -1;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (nums[i] == target)
//         {
//             if (start == -1)
//             {
//                 start = i;
//             }
//             end = i;
//         }
//     }

//     return {start, end};
// }

//optimal approach
int firstOcuurence(vector<int> &nums,int target){
        int n = nums.size();
        int ans = -1;
        int low = 0, high = n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid] == target){
                ans = mid;
                high = mid-1;
            }
            else if(target> nums[mid]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }


    int lastOcuurence(vector<int> &nums,int target){
        int n = nums.size();
        int ans = -1;
        int low = 0, high = n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid] == target){
                ans = mid;
                low = mid+1;
            }
            else if(target> nums[mid]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
       int firstOcc =firstOcuurence(nums,target);
       int lastOcc = lastOcuurence(nums,target);
       return {firstOcc, lastOcc};
    }

int main()
{
    int key = 13;
    vector<int> v = {3, 4, 13, 13, 13, 20, 40};
    vector<int> ans = searchRange(v, key);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}