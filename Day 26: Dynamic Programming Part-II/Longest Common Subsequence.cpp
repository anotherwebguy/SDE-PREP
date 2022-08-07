//Method 1 recurr
class Solution {
public:
    int recurr(int i,string text1, int j, string text2){
        if(i<0 || j<0) return 0;
        if(text1[i]==text2[j]) return 1 + recurr(i-1,text1,j-1,text2);
        
        return 0 + max(recurr(i-1,text1,j,text2),recurr(i,text1,j-1,text2));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return recurr(n-1,text1,m-1,text2);
    }
};
//O(2^n * 2^m)

//Method 2 Memoization
class Solution {
public:
    int recurr(int i,string text1, int j, string text2,vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]) return dp[i][j] = 1 + recurr(i-1,text1,j-1,text2,dp);
        
        return dp[i][j] = 0 + max(recurr(i-1,text1,j,text2,dp),recurr(i,text1,j-1,text2,dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return recurr(n-1,text1,m-1,text2,dp);
    }
};
//O(n*m)+O(n)

//Method 3 tabulation
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=0;i<=n;i++) dp[i][0] = 0;
        for(int i=0;i<=m;i++) dp[0][i] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
//O(n*m)
