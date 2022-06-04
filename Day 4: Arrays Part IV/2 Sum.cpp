class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            int x = target-nums[i];
            if(m.find(x)!=m.end()){
                res.push_back(m[x]);
                res.push_back(i);
                break;
            }
            m[nums[i]]=i;
        }
        return res;
    }
};


// O(N)- time
// O(N)-space
