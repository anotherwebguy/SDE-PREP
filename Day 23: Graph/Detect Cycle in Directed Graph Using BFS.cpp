class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto j : adj[i]) indegree[j]++;
        }
        queue<int> q;
        for(int i=0;i<V;i++) if(!indegree[i]) q.push(i);
        int cnt=1;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto it:adj[x]){
                indegree[it]--;
                if(indegree[it]==0) {
                    q.push(it);
                    cnt++;
                }
            }
        }
        if(cnt!=V) return true;
        else return false;
    }
};

//O(V+E)-time
//O(V)-space
