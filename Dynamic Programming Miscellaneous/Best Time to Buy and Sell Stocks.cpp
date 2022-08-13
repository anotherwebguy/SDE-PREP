//Method space optimize
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0],res=0;
        for(int i=1;i<prices.size();i++){
            res = max(res,prices[i]-mini);
            if(prices[i]<mini) mini = prices[i];
        }
        return res;
    }
};
