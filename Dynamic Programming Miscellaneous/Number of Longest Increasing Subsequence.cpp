class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        vector<int> res(nums.size(),1);
        dp[0]=1;
        int maxi = dp[0];
        for(int i=1;i<nums.size();i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    res[i] = res[j];
                } else if(nums[j]<nums[i] && dp[j]+1==dp[i]){
                    res[i]+=res[j];
                }
            }
            maxi = max(maxi,dp[i]);
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(dp[i]==maxi) ans+=res[i];
        }
        return ans;
    }
};
