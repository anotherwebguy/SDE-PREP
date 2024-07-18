class Solution {
public:
    int uniquePaths(int m, int n) {
        int N=m+n-2;
        int r=m-1;
        double res=1;
        for(int i=1;i<=r;i++){
            res=(res*(N-r+i))/i;
        }
        return (int)res;
    }
};

// O(N)-time
// O(1)-space

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,1));
        for (int i=m-2;i>=0;i--){
            for(int j = n-2;j>=0;j--){
                dp[i][j] = dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }

};

// O(M*N) - time
//O(M*N) - space
