//Method 2 : BFS
class Solution {
public:
    bool bfs(int curr, vector<vector<int>> &graph,vector<int> &color){
        queue<int> q;
        q.push(curr);
        color[curr]=0;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto it : graph[x]){
                if(color[it]==-1){
                    color[it]=!color[x];
                    q.push(it);
                } else if(color[it]==color[x]) return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!bfs(i,graph,color)) return false;
            }
        }
        return true;
    }
};
//O(V+E)-time
//O(V)-space
