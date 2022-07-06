
//TC-O(V+E)
//SC-O(V)
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> res;
        queue<int> q;
        vector<int> vis(V,0);
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            for(auto it:adj[curr]){
                if(vis[it]==0){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return res;
    }
};

//Applications
/* Shortest path, MST, Cycle Detection, GPS, Social Network */
