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

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long n=A.size();
    long long SUMn = (n*(n+1))/2;
    long long SUM2n = (n*(n+1)*(2*n+1))/6;
    long long SUM = 0, SUM2 = 0;
    for(int i:A){
        SUM += i;
        SUM2 += (long long)i*(long long)i;
    }
    long long a = SUM2 - SUM2n;
    long long b = SUM - SUMn;
    long long repeat = (a/b + b)/2;
    long long missing = (a/b - b)/2;
    return {(int)repeat, (int)missing};
}

/*
  O(1)-space
  O(n)-time
*/
