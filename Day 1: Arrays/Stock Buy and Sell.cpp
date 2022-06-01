class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=prices[0],maxi=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<min) min=prices[i];
            if(prices[i]>min) maxi=max(maxi,prices[i]-min);
        }
        return maxi;
    }
};
