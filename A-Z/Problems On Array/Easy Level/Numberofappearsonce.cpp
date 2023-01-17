class Solution
{
public:
    // using unordered maps
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto it : nums)
            mp[it]++;

        for (auto z : mp)
            if (z.second == 1)
                return z.first;
        return -1;
    }
};
// using sorting
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i += 2)
        {
            if (nums[i] != nums[i - 1])
                return nums[i - 1];
        }
        return nums[nums.size() - 1];
    }
};

// using sum of element
int singleNumber(vector<int> &nums)
{
    set<int> s;
    int set_sum, array_sum;
    for (auto it : nums)
        s.insert(it);
    // sum of all element of set
    for (auto it : s)
        set_sum += it;
    // sum of all element of array
    for (auto it : nums)
        array_sum += it;
    long long int ans = (2 * (set_sum)-array_sum);
    return ans;
}