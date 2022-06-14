class Solution {
public:
    bool isPalindrome(string s){
        int l=0,r=s.size()-1;
        while(l<=r){
            if(s[l++]!=s[r--]) return false;
        }
        return true;
    }
    
    void solve(int ind,string s, vector<string> &curr, vector<vector<string>> &res){
        if(ind==s.size()){
            res.push_back(curr);
            return;
        }
        for(int i=ind;i<s.size();i++){
            string k = s.substr(ind,i-ind+1);
            if(isPalindrome(k)){
                curr.push_back(k);
                solve(i+1,s,curr,res);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        solve(0,s,curr,res);
        return res;
    }
};

//O(2^n * K * (n/2))-time
//O(K*x)-space
