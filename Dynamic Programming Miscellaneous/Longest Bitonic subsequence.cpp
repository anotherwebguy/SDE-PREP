class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    vector<int> dp(nums.size()),dp1(nums.size(),1);
        dp[0]=1;
        for(int i=1;i<nums.size();i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                }
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=nums.size()-1;j>i;j--){
                if(nums[j]<nums[i] && 1+dp1[j]>dp1[i]){
                    dp1[i] = 1+dp1[j];
                }
            }
        }
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,dp[i]+dp1[i]-1);
        }
        return maxi;
	}
};
