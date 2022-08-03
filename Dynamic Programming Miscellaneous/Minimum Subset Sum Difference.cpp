int Solution::solve(vector<int> &nums) {
    int sum=0,n = nums.size();
    for(auto i:nums) sum+=i;
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0) dp[i][j]=false;
            if(j==0) dp[i][j]=true;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(nums[i-1]<=j){
                dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
            } else
                dp[i][j]=dp[i-1][j];
        }
    }
    int diff = INT_MAX;
    for(int j=sum/2;j>=0;j--){
        if(dp[nums.size()][j]){
            diff = sum-2*j;
            break;
        }
    }
    return diff;
}
//O(n*sum)
