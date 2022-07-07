class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCyclePresent(int curr,int parent,vector<int> adj[],vector<int> &vis){
        vis[curr]=1;
        for(auto it : adj[curr]){
            if(!vis[it]){
                if(isCyclePresent(it,curr,adj,vis)) return true;
            } else if(parent!=it) return true;
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(isCyclePresent(i,-1,adj,vis)) return true;
            }
        }
        return false;
    }
};

//O(V+E)-time
//O(V)-space
