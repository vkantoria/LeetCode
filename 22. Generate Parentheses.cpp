/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

class Solution {
public:
      vector<string> ans;
    
    void helper(string s, int m, int n)
    {
        if(m == 0 && n == 0)
        {
            ans.push_back(s);
            return;
        }
        if(m>0)
        {
            string opt1 = s;
            opt1 += "(";
            helper(opt1,m-1,n);
            opt1.pop_back();
        }
        if(n>m)
        {   
            string opt2 = s;
            opt2 += ")";
            helper(opt2,m,n-1);
            opt2.pop_back();
        } 
    }
    
    vector<string> generateParenthesis(int n) {
      
        
        helper("(",n-1,n);
        
        return ans;
        
    }
};
