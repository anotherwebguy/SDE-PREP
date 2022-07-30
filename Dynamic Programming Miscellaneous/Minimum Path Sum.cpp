//Method 1 memoiz
class Solution {
public:
    int dp[300][300];
    int helper(int n, int m,vector<vector<int>>& grid){
        if(n==0 && m==0) return dp[n][m] = grid[n][m];
        if(dp[n][m]!=-1) return dp[n][m];
        if(n==0) return dp[n][m]=grid[n][m]+helper(n,m-1,grid);
        if(m==0) return dp[n][m]=grid[n][m]+helper(n-1,m,grid);
        return dp[n][m]=grid[n][m]+min(helper(n,m-1,grid),helper(n-1,m,grid));
    }
                              
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return helper(n-1,m-1,grid);
    }
};

//Method 2 dp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=1;i<n;i++){
            grid[i][0]+=grid[i-1][0];
        }
        for(int i=1;i<m;i++){
            grid[0][i]+=grid[0][i-1];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid[n-1][m-1];
    }
};
