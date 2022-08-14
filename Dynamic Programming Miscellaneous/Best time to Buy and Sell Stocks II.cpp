//Method 1 recurr
class Solution {
public:
    int recurr(int i, vector<int>& prices,int buy){
        if(i==prices.size()){
            return 0;
        }
        if(buy==1){
            return max(-prices[i]+recurr(i+1,prices,0),0+recurr(i+1,prices,1));
        } else {
            return max(prices[i]+recurr(i+1,prices,1),0+recurr(i+1,prices,0));
        }
    }
    int maxProfit(vector<int>& prices) {
        return recurr(0,prices,1);
    }
};
//O(2^n)

//Method 2 memoiz
class Solution {
public:
    int recurr(int i, vector<int>& prices,int buy,vector<vector<int>> dp){
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy==1){
            return dp[i][buy]=max(-prices[i]+recurr(i+1,prices,0,dp),0+recurr(i+1,prices,1,dp));
        } else {
            return dp[i][buy]=max(prices[i]+recurr(i+1,prices,1,dp),0+recurr(i+1,prices,0,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return recurr(0,prices,1,dp);
    }
};

//method 3 dp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n][0]=0,dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j==1){
                    dp[i][j] = max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);
                } else {
                    dp[i][j] = max(prices[i]+dp[i+1][1],0+dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};
