#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> st1;
        unordered_set<int> st2;

        for (auto it : nums1)
        {
            st1.insert(it);
        }

        for (auto it : nums2)
        {
            st2.insert(it);
        }

        vector<int> ans;
        for (auto it : st1)
        {
            if (st2.find(it) != st2.end())
            {
                ans.push_back(it);
            }
        }

        return ans;
    }
};

vector<int> getInputVector()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    return arr;
}

int main()
{
    Solution sol;

    // Get input vectors nums1 and nums2
    cout << "Input for nums1:" << endl;
    vector<int> nums1 = getInputVector();

    cout << "Input for nums2:" << endl;
    vector<int> nums2 = getInputVector();

    // Call the intersection function
    vector<int> result = sol.intersection(nums1, nums2);

    // Print the intersection
    cout << "Intersection of nums1 and nums2: ";
    for (auto num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
