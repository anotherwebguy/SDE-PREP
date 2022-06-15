//Approach-1 Recursive
//O(N!*N)-time
//O(N)-space

class Solution {
public:
    void solve(vector<int> nums,vector<int> &curr, vector<vector<int>> &res, bool freq[]){
        if(curr.size()==nums.size()){
            res.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                curr.push_back(nums[i]);
                freq[i]=true;
                solve(nums,curr,res,freq);
                curr.pop_back();
                freq[i]=false;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        bool freq[nums.size()];
        memset(freq,false,sizeof(freq));
        solve(nums,curr,res,freq);
        return res;
    }
};


//Approach-2 Backtracking
//O(N!*N)-time
//O(1)-space

class Solution {
public:
    void solve(int ind,vector<int> nums, vector<vector<int>> &res){
        if(ind==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            solve(ind+1,nums,res);
            swap(nums[ind],nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        solve(0,nums,res);
        return res;
    }
};
