/*
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
 

Constraints:

1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104
*/
class Solution {
public:
    int maxProfit(vector<int>& nums, int fee) {
        
        int n = nums.size();
        //vector<int> buy(n, 0);
        //vector<int> sell(n,0);
        int buy1 = -nums[0], buy2 = 0;
        int sell1 = 0, sell2 = 0;
        //buy[0] = -nums[0];
        //sell[0] = 0;
        
        for(int i=1;i<n;i++)
        {
            buy2 = max(-nums[i] + sell1, buy1);
            sell2 = max(nums[i] + buy1-fee, sell1);
            buy1 = buy2;
            sell1 = sell2;
        }
        
        return sell2;
        
    }
};
