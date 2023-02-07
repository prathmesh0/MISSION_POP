#include <iostream>
#include <vector>
using namespace std;
/*
//brute force  approach
int search(vector<int> &nums, int target)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == target)
            return i;
    }
    return -1;
}
*/
// optimal approach
int search(vector<int> &arr, int target)
{
    int s = 0, e = arr.size() - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        // if left half is sorted
        if (arr[s] <= arr[mid])
        {
            // check if target is present in my left half or not
            if (target >= arr[s] && target <= arr[mid])
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }

        // if right half is sorted
        else
        {
            // check if target is present in my left half or not
            if (target >= arr[mid] && target <= arr[e])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2, 3};
    int target = 3;
    cout << "The index in which the target is present is " << search(nums, target);
    return 0;
}