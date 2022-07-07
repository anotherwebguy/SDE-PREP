class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCyclePresent(int curr,vector<int> adj[],vector<int> &vis){
        queue<pair<int,int>> q;
        vis[curr]=1;
        q.push({curr,-1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,node});
                } else if(parent!=it){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(isCyclePresent(i,adj,vis)) return true;
            }
        }
        return false;
    }
};

//O(V+E)-time
//O(V)-space
