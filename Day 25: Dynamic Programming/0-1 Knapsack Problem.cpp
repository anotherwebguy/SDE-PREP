//Method 1 recursion
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int recurr(int i,int W,int wt[], int val[],int n){
        if(i==0){
            if(wt[0]<=W) return val[0];
            else return 0;
        }
        int nottake = 0+recurr(i-1,W,wt,val,n);
        int take = INT_MIN;
        if(wt[i]<=W){
            take = val[i]+recurr(i-1,W-wt[i],wt,val,n);
        }
        return max(take,nottake);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       return recurr(n-1,W,wt,val,n);
    }
};
//O(2^n)-time

//Method 2 memoization
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int recurr(int i,int W,int wt[], int val[],int n,vector<vector<int>> &dp){
        if(i==0){
            if(wt[0]<=W) return val[0];
            else return 0;
        }
        if(dp[i][W]!=-1) return dp[i][W];
        int nottake = 0+recurr(i-1,W,wt,val,n,dp);
        int take = INT_MIN;
        if(wt[i]<=W){
            take = val[i]+recurr(i-1,W-wt[i],wt,val,n,dp);
        }
        return dp[i][W]=max(take,nottake);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n,vector<int> (W+1,-1));
       return recurr(n-1,W,wt,val,n,dp);
    }
};
//O(n*W)+O(n)-stack space-time & space

//Method 3 dp
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n,vector<int> (W+1,-0));
       for(int i=wt[0];i<=W;i++) dp[0][i]=val[0];
       for(int i=1;i<n;i++){
           for(int j=0;j<=W;j++){
               int notTake = 0+dp[i-1][j];
               int take = INT_MIN;
               if(wt[i]<=j){
                   take = val[i]+dp[i-1][j-wt[i]];
               }
               dp[i][j] = max(take,notTake);
           }
       }
       return dp[n-1][W];
    }
};
//O(N*W)-time & space
