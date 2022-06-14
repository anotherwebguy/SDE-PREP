class Solution {
public:
    
    void solve(int i,vector<int> arr,int target,vector<int> &curr,vector<vector<int>> &res){
        if(target==0){
            res.push_back(curr);
            return;
        }
        for(int j=i;j<arr.size();j++){
            if(j>i && arr[j]==arr[j-1]) continue;
            if(arr[j]>target) break;
            curr.push_back(arr[j]);
            solve(j+1,arr,target-arr[j],curr,res);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,target,curr,res);
        return res;
    }
};

//O(2^n *k)-time
//O(k*x)-space
