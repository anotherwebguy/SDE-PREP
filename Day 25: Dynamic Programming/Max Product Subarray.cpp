class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxpos=nums[0],maxneg=nums[0],ans=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(maxpos,maxneg);
            }
            maxpos = max(nums[i],maxpos*nums[i]);
            maxneg = min(nums[i],maxneg*nums[i]);
            ans = max(ans,maxpos);
        }
        return ans;
    }
};

//O(N)-time
//O(1)-space
