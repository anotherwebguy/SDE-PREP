class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1 , vector<int>(n+1));
        for(auto s: strs){
            int x = count(s.begin(),s.end(),'1');
            int y = s.size()-x;
            for(int i=m;i>=y;i--){
                for(int j=n;j>=x;j--){
                    dp[i][j]=max(1+dp[i-y][j-x],dp[i][j]);
                }
            }
        }
        return dp[m][n];
    }
};

//O(n^3)-time
//O(n^2)-space
