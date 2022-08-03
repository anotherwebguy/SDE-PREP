class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i: nums) sum+=i;
        if(sum%2) return false;
        sum/=2;
        int dp[nums.size()+1][sum+1];
        for(int i=0;i<=nums.size();i++){
            dp[i][0]=1;
        }
        for(int i=0;i<=sum;i++) dp[0][i]=0;
        for(int i=1;i<=nums.size();i++){
            for(int j=1;j<=sum;j++){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[nums.size()][sum];
    }
};
//O(n*sum) time & space
