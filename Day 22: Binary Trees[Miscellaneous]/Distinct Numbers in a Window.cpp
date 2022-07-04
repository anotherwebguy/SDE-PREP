vector<int> Solution::dNums(vector<int> &A, int B) {
    unordered_map<int,int> m;
    vector<int> res;
    int dist=0;
    for(int i=0;i<B;i++){
        if(m[A[i]]==0) dist++;
        m[A[i]]++;
    }
    res.push_back(dist);
    for(int i=B;i<A.size();i++){
        if(m[A[i-B]]==1) dist--;
        m[A[i-B]]--;
        if(m[A[i]]==0) dist++;
        m[A[i]]++;
        res.push_back(dist);
    }
    return res;
}

//O(N)-time & space
