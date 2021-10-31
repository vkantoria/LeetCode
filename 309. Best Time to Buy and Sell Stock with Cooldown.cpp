/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0
 

Constraints:

1 <= prices.length <= 5000
0 <= prices[i] <= 1000
*/

class Solution {
public:
    int maxProfit(vector<int>& nums) {
        
       int n = nums.size();
        if(n == 1 || n == 0)
            return 0;
       vector<int> buy(n, 0);
       vector<int> sell(n,0);
        buy[0] = -nums[0];
        sell[0] = 0;
        buy[1] =  max(-nums[0], -nums[1]);
        sell[1] = max(buy[0]+nums[1], 0);
        
        for(int i=2;i<n;i++)
        {
            buy[i] = max(-nums[i] + sell[i-2], buy[i-1]);
            sell[i] = max(nums[i] + buy[i-1], sell[i-1]);
        }
        
        return sell[n-1];    
    }
};
