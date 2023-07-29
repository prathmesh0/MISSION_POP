#include<bits/stdc++.h>
using namespace std;

//Bruteforce Approach
double median(int arr1[],int arr2[], int m,int n){
    int i =0;
    int j = 0;
    int ans[m+n];
    int k = 0;
    while (i<m && j<n)
    {
        if(arr1[i] < arr2[j]){
            ans[k++] = arr1[i++];
        }
        else{
            ans[k++] = arr2[j++];
        }
    }

    if(i<m){
        while(i<m){
            ans[k++] = arr1[i++];
        }
    }

    if(j<n){
        while(j<n){
            ans[k++] = arr2[j++];
        }
    }
     n = m+n;
     if(n%2==1){
        return (ans[((n+1)/2)-1]);
     }
     else{
        return ((float)(ans[(n/2)-1])+ (float)(ans[n/2]))/2;
     }
    
}

//LeetCode 
//Optimal Approach
// double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         if(nums2.size() < nums1.size())
//             return findMedianSortedArrays(nums2, nums1);
//         int n1 = nums1.size();
//         int n2 = nums2.size();
//         int low = 0 ,high = n1;
        
//         while(low<=high){
//             int cut1 = (low+high) >> 1;
//             int cut2 = (n1 + n2 + 1)/2 - cut1;
            
//             int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
//             int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
            
//             int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
//             int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];
            
//             if(left1 <= right2 && left2 <= right1){
//                 if((n1+n2)%2 == 0)
//                     return (max(left1, left2) + min(right1, right2))/2.0;
//                 else
//                     return max(left1, left2);
//             }
//             else if(left1 > right2){
//                 high = cut1 - 1;
//             }
//             else{
//                 low = cut1 + 1;
//             }
//         }
//         return 0.0;
//     }

int main(){
    int nums1[] = {1,4,7,10,12};
    int nums2[] = {2,3,6,15};
    int m = sizeof(nums1)/sizeof(nums1[0]);
    int n = sizeof(nums2)/sizeof(nums2[0]);
    cout<<"The median of two sorted array is "<<fixed<<setprecision(5)
    <<median(nums1,nums2,m,n);
    return 0;
}