//Approach 1
//O(2^n * klog(x))-time ......O(2^n) for generating every subset and O(klog(x)) for inserting subset of length k into set of size x
//O(2^n *k)-space

class Solution {
public:
    
    void solve(int ind,vector<int> nums, vector<int> &curr, set<vector<int>> &res){
        if(ind==nums.size()){
           // sort(curr.begin(),curr.end());
            res.insert(curr);
            return;
        }
        curr.push_back(nums[ind]);
        solve(ind+1,nums,curr,res);
        curr.pop_back();
        solve(ind+1,nums,curr,res);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        solve(0,nums,curr,res);
        vector<vector<int>> ans;
        for(auto i:res){
            ans.push_back(i);
        }
        return ans;
    }
};

//Approach 2
//O(2^n * K)-time
//O(2^n * k)-space

class Solution {
public:
    
    void solve(int ind,vector<int> nums, vector<int> &curr, vector<vector<int>> &res){
        res.push_back(curr);
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            curr.push_back(nums[i]);
            solve(i+1,nums,curr,res);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        solve(0,nums,curr,res);
        return res;
    }
};
