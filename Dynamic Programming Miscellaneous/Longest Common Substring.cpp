class Solution{
    public:
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        int res = INT_MIN;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                    res = max(res,dp[i][j]);
                } else dp[i][j] = 0;
            }
        }
        if(res==INT_MIN) return 0;
        return res;
    }
};
//O(n^2)-time &space
