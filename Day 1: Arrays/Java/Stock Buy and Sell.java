class Solution {
    public int maxProfit(int[] prices) {
        int res = 0;
        int mini = prices[0];
        for(int i=1;i<prices.length;i++){
            res = Math.max(res,prices[i]-mini);
            mini = Math.min(mini,prices[i]);
        }
        return res;
    }
}

//O(N) time and O(1) space
