/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 

Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
*/


class Solution {
    
public:
    
     int find(int cor, vector<int> &parent)
    {
        if(cor == parent[cor])
        {
            return cor;
        }
        parent[cor] = find(parent[cor], parent);
        
        return parent[cor];
    }
        
    void Union(int x, int y, vector<int> &rank, vector<int> &parent)
    {
      int x_rep = find(x, parent);
      int y_rep = find(y, parent);
        
        if(x_rep == y_rep) return;
        
        if(rank[x_rep] < rank[y_rep])
        {
            parent[x_rep] = y_rep;
        }
        else if(rank[y_rep] < rank[x_rep])
        {
            parent[y_rep] = x_rep;
        }
        else
        {
            parent[y_rep]= x_rep;
            rank[x_rep]++;
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int m = isConnected.size();
        int n = isConnected[0].size();
    
        vector<int> parent(m,0);
        vector<int> rank(m,0);
        
        vector<int> v[m];
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j] == 1)
                {
                     v[i].push_back(j);
                }
               
            }
        }
        
        for(int i=0;i<m;i++)
        {
            parent[i] = i;
        }
        
        for(int i=0;i<m;i++)
        {
            for(auto r: v[i])
            {
                Union(i,r,rank,parent);
            }
        }
        

        set<int> st;
        for(int i=0;i<m;i++)
         {  
            st.insert(find(i,parent));
        }
        
        return st.size();


        
        
    }
};
