//Method 1: DFS
class Solution {
public:
    bool dfs(int curr, vector<vector<int>> &graph,vector<int> &color,int col){
        color[curr]=col;
        for(auto it: graph[curr]){
            if(color[it]==-1){
                if(!dfs(it,graph,color,!col)) return false;
            } else if(color[it]==color[curr]) return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        int col=0;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!dfs(i,graph,color,col)) return false;
            }
        }
        return true;
    }
};
//O(V+E)-time
//O(V)-space
