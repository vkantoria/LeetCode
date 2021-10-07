/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<int> res(2);
        
       vector<pair<int,int>> p(n);
        
        for(int i=0;i<n;i++)
        {
            p[i] = {nums[i],i};
        }
        
        sort(p.begin(),p.end());
     
        int i=0,j=n-1;
        while(i<j)
        {
            if((p[i].first + p[j].first) == target)
            {
                res[0] = p[i].second;
                res[1] = p[j].second;
                break;
            }    
            else if((p[i].first + p[j].first)>target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
       return res;
    }
};





