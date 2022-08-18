class Solution {
public:
    bool compare(string &x, string &y){
        if(x.size()!=y.size()+1) return false;
        int i=0,j=0;
        while(i<x.size()){
            if(x[i]==y[j]) i++,j++;
            else i++;
        }
        return (i==x.size() && j==y.size());
    }
    
    static bool comp(string &s1,string &s2){
        return s1.size()<s2.size();
    }
    
    int longestStrChain(vector<string>& nums) {
        sort(nums.begin(),nums.end(),comp);
        vector<int> dp(nums.size());
        dp[0]=1;
        for(int i=1;i<nums.size();i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(compare(nums[i],nums[j]) && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
