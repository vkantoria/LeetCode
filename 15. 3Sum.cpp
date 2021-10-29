/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 

Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int k=0;k<n-2;k++)
        {
            if(k!=0 && nums[k] == nums[k-1]) continue;
            if(nums[k]>0)
            {
                return v;
            }
            
            int start = k+1;
            int end = n-1;
            while(start<end)
            {
                int sum = nums[k] + nums[start] + nums[end];
                
                if(sum == 0)
                {
                    v.push_back({nums[k],nums[start],nums[end]});
                    start++;
                    end--;
                    while(start<end && nums[start] == nums[start-1])
                    {
                        start++;  
                    }       
                    
                }
                else if(sum>0)
                {
                    end--;
                }
                else
                {
                    start++;
                }
            }
            
        }
        return v;
        
    }
};
