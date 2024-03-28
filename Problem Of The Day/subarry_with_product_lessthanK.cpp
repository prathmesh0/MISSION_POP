#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanKApproach1(vector<int> &nums, int k)
    {
        if (k <= 1)
        {
            return 0;
        }
        int n = nums.size();
        int s = 0;
        long prod = 1;
        int count = 0;
        for (int e = 0; e < n; e++)
        {
            prod *= nums[e];

            while (prod >= k && s < n)
            {
                prod = prod / nums[s];
                s++;
            }
            if (prod < k)
            {
                count += e - s + 1;
            }
        }
        return count;
    }

    int numSubarrayProductLessThanKApproach2(vector<int> &nums, int k)
    {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int product = 1;
            for (int j = i; j < n; j++)
            {
                product *= nums[j];
                if (product < k)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
        }
        return count;
    }

    void getInput(vector<int> &nums, int &k)
    {
        int n;
        cout << "Enter the size of the array: ";
        cin >> n;
        cout << "Enter the elements of the array: ";
        nums.resize(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> nums[i];
        }
        cout << "Enter the value of k: ";
        cin >> k;
    }
};

int main()
{
    Solution solution;
    vector<int> nums;
    int k;

    solution.getInput(nums, k);

    int result1 = solution.numSubarrayProductLessThanKApproach1(nums, k);
    cout << "Approach 1 Result: " << result1 << endl;

    int result2 = solution.numSubarrayProductLessThanKApproach2(nums, k);
    cout << "Approach 2 Result: " << result2 << endl;

    return 0;
}
