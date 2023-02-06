class Solution
{

public:
    int first_Occurence(vector<int> &arr, int target)
    {
        int s = 0;
        int e = arr.size() - 1;
        int ans = -1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (target == arr[mid])
            {
                ans = mid;
                e = mid - 1;
            }
            else if (target > arr[mid])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return ans;
    }

public:
    int last_Occurence(vector<int> &arr, int target)
    {
        int s = 0;
        int e = arr.size() - 1;
        int ans = -1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (target == arr[mid])
            {
                ans = mid;
                s = mid + 1;
            }
            else if (target > arr[mid])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans;
        int firstOccur = first_Occurence(nums, target);
        int lastOccur = last_Occurence(nums, target);
        ans.push_back(firstOccur);
        ans.push_back(lastOccur);
        return ans;
    }
};