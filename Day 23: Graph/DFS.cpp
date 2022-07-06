class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfs(int curr,vector<int> adj[],bool vis[], vector<int> &res){
        res.push_back(curr);
        vis[curr]=true;
        for(auto it:adj[curr]){
            if(vis[it]==false){
                dfs(it,adj,vis,res);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        bool vis[V] = {false};
        vector<int> res;
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                dfs(i,adj,vis,res);
            }
        }
        return res;
    }
};
//Tc-O(V+E)
//Sc-O(V)
