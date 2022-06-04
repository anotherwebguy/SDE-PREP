class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int st=0,maxi=0;
        for(int i=0;i<s.size();i++){
            if(m.count(s[i])){
                st=max(st,m[s[i]]+1);
            }
            m[s[i]]=i;
            maxi=max(maxi,i-st+1);
        }
        return maxi;
    }
};

// O(N)-time
// O(N)-space
