class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        int curr=0;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=res.back()[1]){
                res.back()[0]=min(res.back()[0],intervals[i][0]);
                res.back()[1]=max(res.back()[1],intervals[i][1]);
            } else res.push_back(intervals[i]);
        }
        return res;
    }
};



/*
  O(NlogN)+O(N)-Time approach
  O(N)-Space approach
*/
