class Solution {
    public int maxSubArray(int[] nums) {
        int res = nums[0];
        int curr = 0;
        for(int i=0;i<nums.length;i++){
            curr += nums[i];
            res = Math.max(res,curr);
            if(curr<0) curr = 0;
        }
        return res;
    }
}

//O(n) time and O(1) space
