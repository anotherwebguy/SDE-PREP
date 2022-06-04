int Solution::solve(vector<int> &A, int B) {
    int xori=0;
    map<int,int> m;
    int cnt=0;
    for(int i=0;i<A.size();i++){
        xori^=A[i];
        if(xori==B) cnt++;
        int y=0;
        y=xori^B;
        if(m.count(y)){
            cnt+=m[y];
        }
        m[xori]++;
    }
    return cnt;
}

// O(Nlogn)-time
// O(N)-space
