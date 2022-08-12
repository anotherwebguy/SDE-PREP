//method recurr
class Solution {
public:
    int recurr(int i, string s,int j,string t ){
        if(j<0){
            return 1;
        } else if(i<0) return 0;
        if(s[i]==t[j]) return recurr(i-1,s,j-1,t)+recurr(i-1,s,j,t);
        else return recurr(i-1,s,j,t);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        return recurr(n-1,s,m-1,t);
    }
};
//O(2^n)

//method memoiz
class Solution {
public:
    int recurr(int i, string s,int j,string t,vector<vector<int>> &dp){
        if(j<0){
            return 1;
        } else if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]=recurr(i-1,s,j-1,t,dp)+recurr(i-1,s,j,t,dp);
        else return dp[i][j]=recurr(i-1,s,j,t,dp);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return recurr(n-1,s,m-1,t,dp);
    }
};


//method dp

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<double>> dp(n+1,vector<double>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                } else dp[i][j] = dp[i-1][j];
            }
        }
        return (int)dp[n][m];
    }
};
