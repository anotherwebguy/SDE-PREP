
//Method 1
//O(N*M)-time & space
class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &vis){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0' || vis[i][j]==1){
            return;
        }
        vis[i][j]=1;
        dfs(i+1,j,grid,vis);
        dfs(i-1,j,grid,vis);
        dfs(i,j+1,grid,vis);
        dfs(i,j-1,grid,vis);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i = 0; i<n ; i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(i,j,grid,vis);
                    count++;
                }
            }
        }
        return count;
    }
};



//Method 2
//O(N*M)-time
//O(1)-space
class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0'){
            return;
        }
        grid[i][j]='0';
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i<n ; i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' ){
                    dfs(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};
