class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        const int n = nums.size();
        vector<vector<int>> v = {};
        int l , r;
        for(int i = 0; i < n ; i++) {
            // Skipping dupplicates
            if(i && nums[i] == nums[i-1])
                continue;
        
            // 2 Pointer
            l = i + 1;
            r = n - 1;
            while( l < r ) {
                if(nums[i] + nums[l] + nums[r] > 0)
                    r--;
                else if(nums[i] + nums[l] + nums[r] < 0)
                    l++;
                else {
                    v.push_back({nums[i] , nums[l] , nums[r]});
                    int le = nums[l] , re = nums[r];
                    // Skipping dupplicates
                    while(l < r && nums[l] == le)
                        l++;
                    while(l < r && nums[r] == re)
                        r--;
                }
            }
        }
        return v;
    }
};
