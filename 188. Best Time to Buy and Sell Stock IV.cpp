/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

Constraints:

0 <= k <= 100
0 <= prices.length <= 1000
0 <= prices[i] <= 1000
*/

class Solution {
public:
     int dp[1001][101][2];
    
     int helper(vector<int>& prices, int k, int i, int state)
     {
         
         if(k<=0)
         {
             return 0;
         }
         if(i>=prices.size())
         {
             return 0;
         }
         
         if(dp[i][k][state] != -1)
             return dp[i][k][state];
         
         if(state == 0)
         {
             return dp[i][k][state] = max(-prices[i] + helper(prices, k, i+1, 1), helper(prices,k,i+1,0));
         }
         
         if(state == 1)
         {
             return dp[i][k][state] = max(prices[i] + helper(prices, k-1, i+1, 0), helper(prices, k, i+1, 1));  
         }
             return dp[i][k][state];
     }
    
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        memset(dp, -1, sizeof(dp));
        helper(prices, k, 0, 0);
        return max(dp[0][k][0], 0);
        
        
    }
};
