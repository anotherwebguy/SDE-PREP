class Solution {
    public int findDuplicate(int[] nums) {
        int tort = nums[0], hare = nums[0];
        do {
            tort = nums[tort];
            hare = nums[nums[hare]];
        } while(tort!=hare);
        tort = nums[0];
        while(tort!=hare){
            tort = nums[tort];
            hare = nums[hare];
        }
        return tort;
    }
}

//O(N) time
