class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0;
         int curr=0;
        for(int i=0; i<nums.size(); i++){
             if(nums[i]==1){
                 curr++;
                 res=max(curr,res);
             }
            else
                curr=0;
        }
        return res;
    }
};

//O(N)-time
//O(1)-space
