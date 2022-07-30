//Method memoiz
class Solution {
public:
    int dp[205][205];
    int recurr(vector<vector<int>> &triangle,int i, int j){
        if(i==triangle.size()-1) return dp[i][j]=triangle[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down = triangle[i][j]+recurr(triangle,i+1,j);
        int right = triangle[i][j]+recurr(triangle,i+1,j+1);
        return dp[i][j]=min(down,right);
    }
    
    int minimumTotal(vector<vector<int>> &triangle) {
        memset(dp,-1,sizeof(dp));
        return recurr(triangle,0,0);
    }
};
//O(n*m)

//Method dp
class Solution {
public:
    
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = triangle.size();
        int dp[n][n];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++) dp[n-1][i]=triangle[n-1][i];
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int d = triangle[i][j]+dp[i+1][j];
                int dj = triangle[i][j]+dp[i+1][j+1];
                dp[i][j] = min(d,dj);
            }
        }
        return dp[0][0];
    }
};
