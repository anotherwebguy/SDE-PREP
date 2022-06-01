class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return;
        int i=n-2;
        while(i>=0 && nums[i]>=nums[i+1]) i--;
        if(i>=0){
            int j=n-1;
            while(nums[i]>=nums[j]) j--;
            swap(nums[i],nums[j]);
        }
        i++;
        int j=n-1;
        while(i<j) swap(nums[i++],nums[j--]);
    }
};
