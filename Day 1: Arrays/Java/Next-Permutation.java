class Solution {
    public void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public void nextPermutation(int[] nums) {
        int i = nums.length-2;
        if(nums.length==0) return;
        while(i>=0 && nums[i]>=nums[i+1]){
            i--;
        }
        if(i>=0){
            int j = nums.length-1;
            while(nums[j]<=nums[i]) j--;
            swap(nums,i,j);
        }
        i++;
        int j = nums.length-1;
        while(i<j){
            swap(nums,i++,j--);
        }
    }
}

//O(N) time and O(1) space
