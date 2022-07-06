class Solution {
public:
    bool dfs(int curr, vector<int> adj[], vector<int> &vis, vector<int> &rec){
        vis[curr]=1;
        rec[curr]=1;
        for(auto it: adj[curr]){
            if(!vis[it]){
                if(dfs(it,adj,vis,rec)) return true;
            } else if(rec[it]==1) return true;
        }
        rec[curr]=0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i =0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> vis(numCourses,0);
        vector<int> rec(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,rec)) return false;
            }
        }
        return true;
    }
};

//O(V+E)-time
//O(2*V)-space
