//Method 1 recurr
class Solution {
public:
    int recurr(int i, int amount, vector<int> &coins){
        if(i==0){
            if(amount%coins[i]==0) return 1;
            else return 0;
        }
        int notTake = 0 + recurr(i-1,amount,coins);
        int take = 0;
        if(coins[i]<=amount){
            take = recurr(i,amount-coins[i],coins);
        }
        return take+notTake;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return recurr(n-1,amount,coins);
    }
};

//Method 2 memoiz
class Solution {
public:
    int recurr(int i, int amount, vector<int> &coins,vector<vector<int>> &dp){
        if(i==0){
            if(amount%coins[i]==0) return 1;
            else return 0;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int notTake = 0 + recurr(i-1,amount,coins,dp);
        int take = 0;
        if(coins[i]<=amount){
            take = recurr(i,amount-coins[i],coins,dp);
        }
        return dp[i][amount]=take+notTake;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return recurr(n-1,amount,coins,dp);
    }
};

//dp same as coin change just replace min with plus and base case with 1
