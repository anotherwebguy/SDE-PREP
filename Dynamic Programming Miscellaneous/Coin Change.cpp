//Method 1 recursion
class Solution {
public:
    int recurr(int i, int amount, vector<int> &coins){
        if(i==0){
            if(amount%coins[i]==0) return amount/coins[i];
            else return 1e9;
        }
        int notTake = 0 + recurr(i-1,amount,coins);
        int take = INT_MAX;
        if(coins[i]<=amount){
            take = 1 + recurr(i,amount-coins[i],coins);
        }
        return min(take,notTake);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = recurr(n-1,amount,coins);
        if(ans==1e9) return -1;
        else return ans;
    }
};
//O(2^n)-time

//Method 2 memoization
class Solution {
public:
    int recurr(int i, int amount, vector<int> &coins,vector<vector<int>> &dp){
        if(i==0){
            if(amount%coins[i]==0) return amount/coins[i];
            else return 1e9;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int notTake = 0 + recurr(i-1,amount,coins,dp);
        int take = INT_MAX;
        if(coins[i]<=amount){
            take = 1 + recurr(i,amount-coins[i],coins,dp);
        }
        return dp[i][amount]=min(take,notTake);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = recurr(n-1,amount,coins,dp);
        if(ans==1e9) return -1;
        else return ans;
    }
};
//O(N*amount)+O(n)-extra stack space

//Method 3 dp
class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        for(int i=0;i<=amount;i++) {
            if(i%coins[0]==0) dp[0][i] = i/coins[0];
            else dp[0][i] = 1e9;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int notTake = dp[i-1][j];
                int take = INT_MAX;
                if(coins[i]<=j){
                    take = 1+dp[i][j-coins[i]];
                }
                dp[i][j] = min(take,notTake);
            }
        }
        int ans = dp[n-1][amount];
        if(ans==1e9) return -1;
        return ans;
    }
};
//O(N*amount)

//Method 4 dp 1-D
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1,0), curr(amount+1,0);
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) prev[i] = i/coins[0];
            else prev[i] = 1e9;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int notTake = 0 + prev[j];
                int take = INT_MAX;
                if(coins[i]<=j){
                    take = 1 + curr[j-coins[i]];
                }
                curr[j] = min(take,notTake);
            }
            prev=curr;
        }
        int ans = prev[amount];
        if(ans==1e9) return -1;
        return ans;
    }
};
//O(n)-space
