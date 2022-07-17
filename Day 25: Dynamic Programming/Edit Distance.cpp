//method-1
//O(3^m)-time & space
class Solution {
public:
    int dp[502][502];
    int helper(string word1,int m,string word2,int n){
        if(m==0) return n;
        if(n==0) return m;
        if(dp[m][n]!=-1) return dp[m][n];
        if(word1[m-1]==word2[n-1]) return dp[m][n]=helper(word1,m-1,word2,n-1);
        return dp[m][n]=1+min(helper(word1,m-1,word2,n-1),min(helper(word1,m-1,word2,n),helper(word1,m,word2,n-1)));
    }
    
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        memset(dp,-1,sizeof(dp));
        return helper(word1,m,word2,n);
    }
};

//method-2
//O(m*n)-time & space
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        int dp[n+1][m+1];
        memset(dp,-1,sizeof(dp));
        if(n==0 || m==0) return max(n,m);
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int i=0;i<=m;i++) dp[0][i]=i;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                } else {
                    dp[i][j] = min(1+dp[i-1][j],min(1+dp[i][j-1],1+dp[i-1][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};
