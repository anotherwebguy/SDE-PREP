class Solution {
public:
    vector<int> computelps(string s){
        int n = s.size();
        vector<int> lps(n,0);
        int l=0,r=1;
        while(r<n){
            if(s[l]==s[r]){
                lps[r]=l+1;
                l++;
                r++;
            } else if(l>0) l=lps[l-1];
            else r++;
        }
        return lps;
    }
    
    int strStr(string haystack, string needle) {
        vector<int> lps = computelps(needle);
        int i=0,j=0;
        while(i<haystack.size()){
            if(haystack[i]==needle[j]){
                ++i;
                ++j;
            } 
            else if(j>0) j=lps[j-1];
            else ++i;
            if(j==needle.size()) return i-j;
        }
        return -1;
    }
};

//O(m+n)-time &space
