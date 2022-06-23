typedef long long ll;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        ll mini=INT_MAX,idx=0;
        int n = strs.size();
        for(int i=0;i<n;i++){
            if(strs[i].size()<mini){
                mini=strs[i].size();
                idx=i;
            }
        }
        string ans="";
        for(int i=0;i<mini;i++){
            for(int j=0;j<n;j++){
                if(strs[idx][i]!=strs[j][i]) return ans;
            }
            ans+=strs[idx][i];
        }
        return ans;
    }
};

//O(m*n)-time
//O(1)-space
