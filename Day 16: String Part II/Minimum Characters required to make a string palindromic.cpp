vector<int> computelps(string s){ 
    vector<int> lps(s.size()); 
    int len=0; 
    lps[0]=0; 
    int i=1; 
    while(i<s.size()){ 
        if(s[i]==s[len]){ 
            len++; 
            lps[i]=len; 
            i++;
        } else { 
            if(len!=0){ 
               len=lps[len-1];
            } else { 
               lps[i]=0; 
               i++; 
            } 
       } 
    } 
    return lps;
} 

int Solution::solve(string A) {
    string rev=A; 
    reverse(rev.begin(),rev.end()); 
    string concat=A+'$'+rev; 
    vector<int> lps=computelps(concat); 
    return (A.size()-lps.back());
}

//O(2*N)-time and space
