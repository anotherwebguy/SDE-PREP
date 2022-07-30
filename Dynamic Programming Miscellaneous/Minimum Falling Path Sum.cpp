//method memoiz
class Solution {
public:
    int dp[105][105];
    int recurr(vector<vector<int>>& a,int i, int j){
        if(j<0 || j>=a[0].size()) return 1e9;
        if(i==0) return a[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int u = a[i][j]+recurr(a,i-1,j);
        int ul = a[i][j]+recurr(a,i-1,j-1);
        int ur = a[i][j]+recurr(a,i-1,j+1);
        return dp[i][j]=min({u,ul,ur});
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof(dp));
        int mini=INT_MAX;
        for(int i=0;i<matrix[0].size();i++){
            mini = min(mini,recurr(matrix,matrix.size()-1,i));
        }
        return mini;
    }
};

//method dp
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        int n = a.size(),m = a[0].size();
        int dp[n][m];
        for(int i=0;i<m;i++) dp[0][i]=a[0][i];
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int ul=1e9,ur=1e9;
                int u = a[i][j]+dp[i-1][j];
                if(j-1>=0) ul = a[i][j]+dp[i-1][j-1];
                if(j+1<m) ur = a[i][j]+dp[i-1][j+1];
                dp[i][j] = min({u,ul,ur});
            }
        }
        int mini = INT_MAX;
        for(int i=0;i<m;i++) mini = min(mini,dp[n-1][i]);
        return mini;
    }
};
