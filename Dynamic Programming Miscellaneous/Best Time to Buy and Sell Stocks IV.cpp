class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int>(k+1,0)));
        for(int i=0;i<=k;i++){
            for(int j=0;j<=1;j++){
                dp[n][j][i]=0;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                dp[i][j][0]=0;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int t=1;t<=k;t++){
                    if(j==1){
                        dp[i][j][t] = max(-prices[i]+dp[i+1][0][t],0+dp[i+1][1][t]);
                    } else {
                        dp[i][j][t] = max(prices[i]+dp[i+1][1][t-1],0+dp[i+1][0][t]);
                    }
                }
            }
        }
        return dp[0][1][k];
    }
};
