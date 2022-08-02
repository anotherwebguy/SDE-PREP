//Method 1 recurr O(2^n)
class Solution{   
public:
    bool recurr(int i, int sum,vector<int> &arr){
        if(i==arr.size()){
            if(sum==0) return true;
            else return false;
        }
        bool take=false,notTake=false;
        if(arr[i]<=sum){
            take= recurr(i+1,sum-arr[i],arr);
        } 
        notTake = recurr(i+1,sum,arr);
        return take | notTake;
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        return recurr(0,sum,arr);
    }
};

//Method 2 memoiz O(n*Sum)
class Solution{   
public:
    bool recurr(int i, int sum,vector<int> &arr,vector<vector<int>> &dp){
        if(sum==0) return true;
        if(i==0) return arr[0]==sum;
        bool take=false,notTake=false;
        if(dp[i][sum]!=-1) return dp[i][sum];
        if(arr[i]<=sum){
            take= recurr(i-1,sum-arr[i],arr,dp);
        } 
        notTake = recurr(i-1,sum,arr,dp);
        return dp[i][sum]=take | notTake;
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int>> dp(arr.size(),vector<int>(sum+1,-1));
        return recurr(arr.size()-1,sum,arr,dp);
        
    }
};

//Method 3 dp
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<bool>> dp(arr.size()+1,vector<bool> (sum+1,false));
        for(int i = 0; i<=arr.size(); i++){
            dp[i][0]=true;
        }
        for(int i=0;i<=sum;i++) dp[0][sum]=false;
        for(int i=1;i<=arr.size();i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1]<=j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] | dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[arr.size()][sum];
    }
};
//O(N*N)
