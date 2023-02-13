#include <iostream>
#include <vector>
using namespace std;

// brute force approach
int noOfRotation(vector<int> &v)
{
    int min_element = INT_MAX;
    int ind = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] < min_element)
        {
            min_element = v[i];
            ind = i;
        }
    }
    return ind;
}

// optimal approach
/*
int findKRotation(int arr[], int n) {
        int s =0, e =n-1;
        if(arr[s] <= arr[e]) return 0;
        while(s<=e){
            int mid = s+(e-s)/2;
            // if first element is mid or
            // last element is mid
            // then simply use modulo so it
            // never goes out of bound.
            int prev = (mid-1+n)%n;
            int after = (mid+1)%n;
            if(arr [mid] <= arr[prev] && arr[mid] <= arr[after]){
                return mid;
            }
            else if( arr[0] <= arr[mid]){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return 0;
    }
*/
int main()
{
    vector<int> v = {4, 5, 1, 2, 3};
    int ans = noOfRotation(v);
    cout << "Array is rotated " << ans << " number of times" << endl;

    return 0;
}