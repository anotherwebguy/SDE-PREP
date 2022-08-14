///Method 1 recurr
class Solution {
public:
    int recurr(int i, vector<int>& prices,int buy,int cap){
        if(cap==0) return 0;
        if(i==prices.size()){
            return 0;
        }
        if(buy==1){
            return max(-prices[i]+recurr(i+1,prices,0,cap),0+recurr(i+1,prices,1,cap));
        } else {
            return max(prices[i]+recurr(i+1,prices,1,cap-1),0+recurr(i+1,prices,0,cap));
        }
    }
    
    int maxProfit(vector<int>& prices) {
        return recurr(0,prices,1,2);
    }
};

//method 2 memoization
class Solution {
public:
    int recurr(int i, vector<int>& prices,int buy,int cap,vector<vector<vector<int>>> &dp){
        if(cap==0) return 0;
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        if(buy==1){
            return dp[i][buy][cap]=max(-prices[i]+recurr(i+1,prices,0,cap,dp),0+recurr(i+1,prices,1,cap,dp));
        } else {
            return dp[i][buy][cap]=max(prices[i]+recurr(i+1,prices,1,cap-1,dp),0+recurr(i+1,prices,0,cap,dp));
        }
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int>(3,-1)));
        return recurr(0,prices,1,2,dp);
    }
};

//method 3 dp
class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int>(3,0)));
        dp[n][0][0]=0,dp[n][0][1]=0,dp[n][0][2]=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                dp[i][j][0]=0;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=1;k<3;k++){
                    if(j==1){
                        dp[i][j][k] = max(-prices[i]+dp[i+1][0][k],0+dp[i+1][1][k]);
                    } else {
                        dp[i][j][k] = max(prices[i]+dp[i+1][1][k-1],0+dp[i+1][0][k]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};
