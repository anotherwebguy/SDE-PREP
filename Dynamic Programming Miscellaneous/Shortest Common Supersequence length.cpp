class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string s1, string s2, int n, int m)
    {
        //code here int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return m+n-dp[n][m];
    }
};
