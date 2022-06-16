/*
1st approach use maps
2nd approach use xor
3rd approach use binary search
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0,h=nums.size()-2;
        while(l<=h){
            int m = l+(h-l)/2;
            if(nums[m]==nums[m^1]){
                l=m+1;
            } else h=m-1;
        }
        return nums[l];
    }
};

//O(Log(n))-time
//O(1)-space
