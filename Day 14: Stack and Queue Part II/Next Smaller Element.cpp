vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> s;
    vector<int> g;
    for(auto i:A){
        while(!s.empty() && s.top()>=i) s.pop();
        if(s.empty()) g.push_back(-1);
        else g.push_back(s.top());
        s.push(i);
    }
    return g;
}

//O(N)-time
//O(N)-space
