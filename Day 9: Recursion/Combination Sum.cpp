class Solution {
public:
    void solve(int ind,vector<int> candidates,int target,vector<int> &curr, vector<vector<int>> &res){
        if(ind==candidates.size()){
            if(target==0){
                res.push_back(curr);
            }
            return;
        }
        if(candidates[ind]<=target){
            curr.push_back(candidates[ind]);
            solve(ind,candidates,target-candidates[ind],curr,res);
            curr.pop_back();
        }
        solve(ind+1,candidates,target,curr,res);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
      //  sort(candidates.begin(),candidates.end());
        solve(0,candidates,target,curr,res);
        return res;
    }
};

//O(2^t *k)-time
//O(x*k)-space
