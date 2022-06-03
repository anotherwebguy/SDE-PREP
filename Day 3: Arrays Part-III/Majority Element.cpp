class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj=0,cnt=0;
        for(int i=0;i<nums.size();i++){
            if(cnt==0) maj=nums[i];
            if(maj==nums[i]) cnt++;
            else cnt--;
        }
        return maj;
    }
};

// O(n)-time
// O(1)-space
