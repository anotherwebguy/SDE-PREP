class Solution {
public:
    string longestPalindrome(string s) {
        int start=0,maxi=0;
        int n = s.size();
        if(n==0 || n==1) return s;
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        maxi=1;
        for(int i=0;i<=n;i++){
            dp[i][i]=1;
        }
        for(int i=0;i<n;i++){
            if(s[i]==s[i+1]){
                maxi=2;
                start=i;
                dp[i][i+1]=1;
            }
        }
        for(int k=3;k<=n;k++){
            for(int i=0;i<n-k+1;i++){
                int j=i+k-1;
                if(dp[i+1][j-1] && s[i]==s[j]){
                    dp[i][j]=1;
                    if(k>maxi){
                        maxi=k;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,maxi);
    }
};

//O(N^2)-time
//O(N^2)-space
