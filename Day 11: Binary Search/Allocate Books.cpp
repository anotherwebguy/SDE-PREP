int f(vector<int> &A, int &maxPages) {
    int numStudents = 1;
    int pages = 0;
    for (int i = 0; i < A.size(); ++i) {
        pages += A[i];
        if (pages > maxPages) {
            pages = A[i];
            numStudents++;
        }
    }
    return numStudents;
}
int Solution::books(vector<int> &A, int B) {
    int n = A.size();
    if (n < B)
        return -1;

    int l = INT_MIN, ans, p;
    long long r = 0;
    for (int i = 0; i < n; i++) {
        l = max(l, A[i]);
        r += A[i];
    }

    while (l <= r)
    {
        p = l + (r - l)/2;
        int s = f(A, p);
        // cout<<l<<' '<<r<<' '<<p<<' '<<s<<endl;
        if (s > B) {
            l = p + 1;
        } else {
            ans = p;
            r = p - 1;
        }
    }
    return ans;
}
