//Method 1 memoization
class Solution {
public:
    int dp[105][105];
    int recurr(vector<vector<int>>& a,int i,int j){
        if(i>=0 && j>=0 && a[i][j]==1) return dp[i][j]=0;
        if(i==0 && j==0) return dp[i][j]=1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = recurr(a,i-1,j);
        int left = recurr(a,i,j-1);
        return dp[i][j] = up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp,-1,sizeof(dp));
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        return recurr(obstacleGrid,n-1,m-1);
    }
};

//Method 2 dp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        int dp[n][m];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else if(i==0 && j==0) dp[i][j]=1;
                else {
                    int up=0,left=0;
                    if(i-1>=0) up = dp[i-1][j];
                    if(j-1>=0) left = dp[i][j-1];
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[n-1][m-1];
    }
};
