class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        else if(n==2) return "11";
        string s="11";
        for(int i=3;i<=n;i++){
            string t="";
            int c=1;
            s+='$';
            for(int j=1;j<s.length();j++){
                if(s[j]!=s[j-1]){
                    t+=to_string(c);
                    t+=s[j-1];
                    c=1;
                } 
                else c++;
            }
            s=t;
        }
        return s;
    }
};

//O(n^2)-time 
//O(1)-space
