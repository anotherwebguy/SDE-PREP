//Method 1 recurr
class Solution{
  public:
    int recurr(int i,int rem,int price[]) {
        if(i==0){
            return rem*price[i];
        }
        int notTake = 0 + recurr(i-1,rem,price);
        int take = INT_MIN;
        int len = i+1;
        if(len<=rem){
            take = price[i] + recurr(i,rem-len,price);
        }
        return max(take,notTake);
    }
    
    int cutRod(int price[], int n) {
        //code here
        return recurr(n-1,n,price);
    }
};
//O(2^n)

//Method 2 memoization
class Solution{
  public:
    int recurr(int i,int rem,int price[],vector<vector<int>> &dp) {
        if(i==0){
            return rem*price[i];
        }
        if(dp[i][rem]!=-1) return dp[i][rem];
        int notTake = 0 + recurr(i-1,rem,price,dp);
        int take = INT_MIN;
        int len = i+1;
        if(len<=rem){
            take = price[i] + recurr(i,rem-len,price,dp);
        }
        return dp[i][rem]=max(take,notTake);
    }
    
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        return recurr(n-1,n,price,dp);
    }
};
//O(N^2)

//method 3 dp
class Solution{
  public:
    
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n,vector<int> (n+1,0));
        for(int i=0;i<=n;i++){
            dp[0][i] = i*price[0];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int notTake = 0 + dp[i-1][j];
                int take = INT_MIN;
                int len = i+1;
                if(len<=j){
                    take = price[i]+dp[i][j-len];
                }
                dp[i][j] = max(take,notTake);
            }
        }
        return dp[n-1][n];
    }
};

//Method 4 1d
class Solution{
  public:
    
    int cutRod(int price[], int n) {
        //code here
        vector<int> prev(n+1,0),curr(n+1,0);
        for(int i=0;i<=n;i++){
            prev[i] = i*price[0];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int notTake = 0 + prev[j];
                int take = INT_MIN;
                int len = i+1;
                if(len<=j){
                    take = price[i]+curr[j-len];
                }
                curr[j] = max(take,notTake);
            }
            prev=curr;
        }
        return prev[n];
    }
};
