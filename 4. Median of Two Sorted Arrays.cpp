/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/

class Solution {
public:
    double helper(vector<int>& nums1, vector<int>& nums2, int m, int n)
    {
        int l = 0, h = m;
        
        while(l<=h)
        {
           int cut1 = (h + l)/2;
           int cut2 = (n+m+1)/2 - cut1;
           
           int l1 = cut1-1>=0?nums1[cut1-1]:INT_MIN;
           int l2 = cut2-1>=0?nums2[cut2-1]:INT_MIN;
           int r1 = cut1<m?nums1[cut1]:INT_MAX;
           int r2 = cut2<n?nums2[cut2]:INT_MAX;
            
            if(l1<=r2 && l2<=r1)
            {
                if((n+m)%2 == 0)
                    return (max(l1,l2) + min(r1,r2))/2.0;
                else return max(l1, l2);
            }
            if(l1>r2)
            {
                h = cut1 - 1;
            }
            else l = cut1 + 1;  
        }
      return 0;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        if(m<n)
           return helper(nums1, nums2, m, n); 
        else return helper(nums2, nums1, n, m);    
        
    }
};
