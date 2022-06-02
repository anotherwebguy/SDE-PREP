vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n=A.size();
        vector<int> a(n+1);
        for(int i=0;i<n;i++){
            a[A[i]]++;
        }
        int rep=0,mis=0;
        for(int i=1;i<=n;i++){
            if(a[i]>1){
                rep=i;
            } else if(a[i]==0){
                mis=i;
            }
        }
        return {rep,mis};
}

/*
  O(N)-space
  O(n)-time
*/
