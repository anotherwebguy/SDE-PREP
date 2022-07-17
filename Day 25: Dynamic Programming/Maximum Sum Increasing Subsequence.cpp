class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int dp[n];
	    int ans=arr[0];
	    dp[0]=arr[0];
	    for(int i=1;i<n;i++){
	        dp[i]=arr[i];
	        int temp = INT_MIN;
	        for(int j=0;j<i;j++){
	            if(arr[i]>arr[j]){
	                temp = max(temp,arr[i]+dp[j]);
	                dp[i]=temp;
	            }
	        }
	        ans = max(ans,dp[i]);
	    }
	    return ans;
	    
	}  
};

//O(N*N)-timr
//O(N)-space
