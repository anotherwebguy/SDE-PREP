//Method 1- recurr
class Solution {
public:
    int recurr(int i, string s1, int j, string s2){
        if(i<0 || j<0) return 0;
        if(s1[i]==s2[j]) return 1+recurr(i-1,s1,j-1,s2);
        else return max(recurr(i-1,s1,j,s2),recurr(i,s1,j-1,s2));
    }
    
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s.begin(),s.end());
        int n = s1.size(), m = s.size();
        return recurr(n-1,s1,m-1,s);
    }
};
//O(2^n)

//method 2 memoiz
class Solution {
public:
    int recurr(int i, string s1, int j, string s2,vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=1+recurr(i-1,s1,j-1,s2,dp);
        else return dp[i][j]=max(recurr(i-1,s1,j,s2,dp),recurr(i,s1,j-1,s2,dp));
    }
    
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s.begin(),s.end());
        int n = s1.size(), m = s.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return recurr(n-1,s1,m-1,s,dp);
    }
};

//method 3 dp
class Solution {
public:
    int longestPalindromeSubseq(string s) {
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
        return dp[n][m];
    }
};
//O(n^2)
