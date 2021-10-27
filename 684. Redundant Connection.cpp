/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

Example 1:


Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
Example 2:


Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
 

Constraints:

n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ai < bi <= edges.length
ai != bi
There are no repeated edges.
The given graph is connected.
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

            if(x_rep == y_rep) 
            {
              return;
            }

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

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int m = edges.size();
    
        vector<int> parent(m+1,0);
        vector<int> rank(m+1,0);
        
        for(int i=0;i<m+1;i++)
        {
            parent[i] = i;
        }
        
        int j=0;
        
        for(j=0;j<m;j++)
        {
              if(find(parent[edges[j][0]], parent) == find(parent[edges[j][1]], parent))
              {
                  return {edges[j][0],edges[j][1]};
              }
              Union(edges[j][0], edges[j][1], rank, parent);
        }
        
       return {1,1};
    }
};
