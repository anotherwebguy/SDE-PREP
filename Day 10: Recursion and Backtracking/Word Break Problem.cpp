void solve(string s, vector<string> &dictionary, string curr, vector<string> &res){
    if(s.size()==0){
        res.push_back(curr);
        return;
    }
    for(int i=0;i<s.size();i++){
        string l = s.substr(0,i+1);
        if(find(dictionary.begin(),dictionary.end(),l)!=dictionary.end()){
            string r = s.substr(i+1,s.size());
            solve(r,dictionary,curr+l+" ",res);
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    vector<string> res;
    solve(s,dictionary,"",res);
    return res;
}

//O(2^n)-time
//O(N^2)-space
