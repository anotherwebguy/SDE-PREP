vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n=A.size(); 
    int m=B.size(); 
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    priority_queue< pair<int, pair<int, int> > > q;
    set<pair<int, int> > st;
    
    int i=n-1, j=m-1;
    
    st.insert({i, j});
    q.push({A[i]+B[j], {i, j}});
    vector<int> ans; 
    
    while(C>0 && q.empty()==false){
        auto tp = q.top(); 
        ans.push_back(tp.first);
        C--;
        auto pr = tp.second;
        q.pop();
        
        int m = pr.first;
        int n = pr.second - 1;
        if( m>=0 && n>=0 && st.find({m, n}) == st.end() ){
            q.push({A[m]+A[n], {m, n}});
            st.insert({m, n});
        }
        
        m = pr.first - 1;
        n = pr.second;
        if( m>=0 && n>=0 && st.find({m, n}) == st.end() ){
            q.push({A[m]+A[n], {m, n}});
            st.insert({m, n});
        }
    }
    
    return ans; 
}
