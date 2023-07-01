#include <bits/stdc++.h>
using namespace std;
// Brute-force
//  int maxElement(vector<int>  &arr){
//      int n = arr.size();
//      sort(arr.begin(), arr.end());
//      return arr[n-1];
//  }

int maxElement(vector<int> &arr)
{
    int maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }
    return maxi;
}

void second_large_small(vector<int> &arr)
{
    int maxi = INT_MIN;
    int mini = INT_MAX;
    int second_max = INT_MIN;
    int second_min = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        maxi = max(maxi, arr[i]);
        mini = min(mini, arr[i]);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < second_min && arr[i] != mini)
        {
            second_min = arr[i];
        }
        if (arr[i] > second_max && arr[i] != maxi)
        {
            second_max = arr[i];
        }
    }
    cout << "Second Minimum = " << second_min << endl;
    cout << "Second Maximum = " << second_max << endl;
}
// Brute force
// bool issorted(vector<int> &arr)
// {
//     int n = arr.size();
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[j] < arr[i])
//                 return false;
//         }
//     }
//     return true;
// }

// optimal  approach
bool issorted(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return false;
    }
    return true;
}

// sorted roteted array
class Solution
{
public:
    bool check(vector<int> &arr)
    {
        int n = arr.size();
        int count = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i - 1] > arr[i])
            {
                count++;
            }
        }
        if (arr[n - 1] > arr[0])
        {
            count++;
        }
        return count <= 1;
    }
};

// brute force
// int removeDuplicateNumber(vector<int> &arr)
// {
//     set<int> st;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         st.insert(arr[i]);
//     }
//     int size = st.size();
//     int j = 0;
//     for (auto it : st)
//     {
//         arr[j] = it;
//         j++;
//     }
//     return size;
// }

int removeDuplicateNumber(vector<int> &nums)
{
    int n = nums.size();
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (nums[i] != nums[j])
        {
            nums[i + 1] = nums[j];
            i++;
        }
    }
    return i + 1;
}

// brute force
// void leftrotatedByOne(vector<int> &arr)
// {
//     int n = arr.size();
//     int temp[n];
//     for (int i = 1; i < n; i++)
//     {
//         temp[i - 1] = arr[i];
//     }
//     temp[n - 1] = arr[0];

//     for (int i = 0; i < n; i++)
//     {
//         cout << temp[i] << " ";
//     }
// }

// optimal approach
void leftrotatedByOne(vector<int> &arr)
{
    int n = arr.size();
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// brute force approach
// void moveZeros(vector<int> &arr)
// {
//     int n = arr.size();
//     int temp[n];
//     int k = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] != 0)
//         {
//             temp[k] = arr[i];
//             k++;
//         }
//     }
//     while (k < n)
//     {
//         temp[k] = 0;
//         k++;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout << temp[i] << " ";
//     }
// }

// optimal approach
void moveZeros(vector<int> &arr)
{
    int n = arr.size();
    int k = 0;
    while (k < n)
    {
        if (arr[k] == 0)
        {
            break;
        }
        else
        {
            k++;
        }
    }
    int i = k;
    int j = k + 1;
    while (i < n && j < n)
    {
        if (arr[j] != 0)
        {
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int linearSearch(vector<int> &arr, int key)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

// brute force
// void unionOfTwoSOrtedarray(vector<int> &arr1, vector<int> &arr2)
// {
//     set<int> st;
//     vector<int> ans;
//     for (auto it1 : arr1)
//     {
//         st.insert(it1);
//     }
//     for (auto it2 : arr2)
//     {
//         st.insert(it2);
//     }
//     for (auto x : st)
//     {
//         ans.push_back(x);
//     }
//     for (auto t : ans)
//     {
//         cout << t << " ";
//     }
// }

// brute force
// void unionOfTwoSOrtedarray(vector<int> &arr1, vector<int> &arr2)
// {
//     map<int, int> mp;
//     vector<int> ans;
//     for (auto it : arr1)
//     {
//         mp[it]++;
//     }
//     for (auto it : arr2)
//     {
//         mp[it]++;
//     }

//     for (auto x : mp)
//     {
//         ans.push_back(x.first);
//     }
//     for (auto t : ans)
//     {
//         cout << t << " ";
//     }
// }

// better approach
void unionOfTwoSOrtedarray(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            if (ans.size() == 0 || ans.back() != arr1[i])
            {
                {
                    ans.push_back(arr1[i]);
                }
            }
            i++;
        }
        else
        {
            if (ans.size() == 0 || ans.back() != arr2[j])
            {
                {
                    ans.push_back(arr2[j]);
                }
            }
            j++;
        }
    }

    while (i < n)
    {

        if (ans.back() != arr1[i])
            ans.push_back(arr1[i]);
        i++;
    }

    while (j < m)
    {
        if (ans.back() != arr2[j])
            ans.push_back(arr2[j]);
        j++;
    }

    for (auto t : ans)
    {
        cout << t << " ";
    }
}

// brute force
//  int missingElement(vector<int> &arr){
//      int n = arr.size();
//      for(int i = 0; i<=n; i++){
//          int flag =0;
//          for(int j = 0; j<arr.size(); j++){
//              if(i == arr[j]){
//                  flag = 1;
//                  break;
//              }
//          }
//          if(flag == 0){
//              return i;
//          }
//      }
//      return -1;
//  }

// better approach
// int missingElement(vector<int> &arr)
// {
//     int n = arr.size();
//     int hash[n + 1] = {0};
//     for (int i = 0; i < n; i++)
//     {
//         hash[arr[i]]++;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (hash[i] == 0)
//             return i;
//     }
//     return -1;
// }

// optimal approach
// int missingElement(vector<int> &nums)
// {

//     int n = nums.size();
//     int total = (n * (n + 1)) / 2;
//     int sum = 0;
//     for (auto it : nums)
//     {
//         sum += it;
//     }
//     return (total - sum);
// }

int maximumOnce(vector<int> &arr)
{
    int count = 0;
    int maxi = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 1)
        {
            count++;
        }
        else
        {
            count = 0;
        }
        maxi = max(maxi, count);
    }
    return maxi;
}

// Brute force approach
//  int  getSingleElement(vector<int> &arr){
//      int n = arr.size();
//      for(int i = 0; i<n; i++){
//          int num = arr[i];
//          int count = 0;
//          for(int j = 0; j<n; j++){
//              if(arr[j] == num){
//                  count++;
//              }
//          }
//          if(count ==1 ) return num;
//      }
//      return -1;
//  }

// better  approach
//  int  getSingleElement(vector<int> &arr){
//      unordered_map<int,int>mpp;
//      for(int i= 0; i<arr.size(); i++){
//          mpp[arr[i]]++;
//      }
//      for(auto it : mpp){
//          if(it.second == 1)
//          return it.first;
//      }
//      return -1;
//  }

// optimal approach
int getSingleElement(vector<int> &arr)
{
    int ans = 0;
    for (auto it : arr)
    {
        ans = ans ^ it;
    }
    return ans;
}

// Naive approach
// int sumk(vector<int> &arr, int key)
// {
//     int n = arr.size();
//     int len = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             long long int s = 0;
//             for (int k = i; k <= j; k++)
//             {
//                 s += arr[k];
//             }
//             if (s == key)
//             {
//                 len = max(len, j - i + 1);
//             }
//         }
//     }
//     return len;
// }

// optimizing the naive approach
int sumk(vector<int> &arr, int key)
{
    int n = arr.size();
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        long long int s = 0;
        for (int j = i; j < n; j++)
        {
            

            s += arr[j];

            if (s == key)
            {
                len = max(len, j - i + 1);
            }
        }
    }
    return len;
}

int main()
{
    vector<int> arr = {1, 0, 1, 1, 1, 1, 0, 1, 1, 4, 1};
    vector<int> arr1 = {2, 3, 5, 1, 9};
    vector<int> arr2 = {1, 2, 3, 4, 5, 6};
    // int maxi = maxElement(arr);
    // cout<<maxi<<endl;
    // second_large_small(arr);
    // bool ans = issorted(arr);
    // cout << ans << endl;
    // int duplicate = removeDuplicateNumber(arr);
    // cout << duplicate << endl;
    // leftrotatedByOne(arr);
    // moveZeros(arr);
    // int index = linearSearch(arr, 8);
    // cout<<index<<endl;
    // unionOfTwoSOrtedarray(arr1, arr2);
    // int missing = missingElement(arr);
    // cout << missing << endl;
    // int maxione = maximumOnce(arr);
    // cout<<maxione<<endl;
    // int single = getSingleElement(arr);
    // cout << single << endl;
    int maxlength = sumk(arr1, 10);
    cout << "Maximum length of subarray = " << maxlength << endl;

    return 0;
}