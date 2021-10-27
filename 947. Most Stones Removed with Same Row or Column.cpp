/*
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

 

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.
Example 3:

Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.
 

Constraints:

1 <= stones.length <= 1000
0 <= xi, yi <= 104
No two stones are at the same coordinate point.
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
        

    
       void Union(int x int y, vector<int> &rank, vector<int> &parent)
        {,
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
    
    

    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();
        
        map<pair<int, int>,int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[{stones[i][0],stones[i][1]}]= i;
        }
        
        vector<int> parent(n,0);
        vector<int> rank(n,0);
        
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                Union(mp[{stones[i][0],stones[i][1]}], mp[{stones[j][0],stones[j][1]}], rank, parent);
                }
            }
        }
        
        set<int> sp;
        
        for(int i=0;i<n;i++)
        {
            sp.insert(find(i,parent));
        }
        return n-sp.size();
    }
};
