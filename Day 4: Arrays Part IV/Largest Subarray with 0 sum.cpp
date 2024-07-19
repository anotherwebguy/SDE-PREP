class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        map<int,int> m;
        int sum = 0, res = 0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==0){
                res = i+1;
            } else if(m.count(sum)){
                res = max(res,i-m[sum]);
            } else m[sum] = i;
        }
        return res;
    }
};

// O(N)-time
// O(N)-space
