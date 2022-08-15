//Method recurr
class Solution {
public:
    int recurr(int i,int prev,vector<int>& nums){
        if(i==nums.size()) return 0;
        int len = 0+recurr(i+1,prev,nums);
        if(prev==-1 || nums[i]>nums[prev]){
            len = max(len,1+recurr(i+1,i,nums));
        }
        return len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        //int ans=1;
        return recurr(0,-1,nums);
    }
};

//Method memoiz
class Solution {
public:
    int recurr(int i,int prev,vector<int>& nums, vector<vector<int>> &dp){
        if(i==nums.size()) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int len = 0+recurr(i+1,prev,nums,dp);
        if(prev==-1 || nums[i]>nums[prev]){
            len = max(len,1+recurr(i+1,i,nums,dp));
        }
        return dp[i][prev+1]=len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return recurr(0,-1,nums,dp);
    }
};

//Method dp 2d
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j = i-1;j>=-1;j--){
                int len = dp[i+1][j+1];
                if(j==-1 || nums[i]>nums[j]) len = max(len,1+dp[i+1][i+1]);
                dp[i][j+1] = len;
            }
        }
        return dp[0][0];
    }
};

//Method dp 1d
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //int ans=1;
        vector<int> dp(nums.size());
        dp[0]=1;
        for(int i=1;i<nums.size();i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};

//Method nlogn
class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        res.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>res.back()) res.push_back(nums[i]);
            else {
                int ind = lower_bound(res.begin(),res.end(),nums[i])-res.begin();
                res[ind] = nums[i];
            }
        }
        return res.size();
    }
};
