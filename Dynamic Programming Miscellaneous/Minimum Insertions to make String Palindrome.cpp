class Solution {
public:
    int minInsertions(string s) {
        string s1 = s;
        reverse(s.begin(),s.end());
        int n = s1.size(), m = s.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return s.size()-dp[n][m];
    }
};

//O(n^2)
