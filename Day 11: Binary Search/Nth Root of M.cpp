double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 1;i<=n;i++) {
        ans = ans * number;
    }
    return ans; 
}

double findNthRootOfM(int n, long long m) {
	// Write your code here.
    double l=1.0,h=(double)m;
    double eps = 1e-7; // number of decimal places+1
    while((h-l)>=eps){
        double mid = (l+h)/2.0;
        if(multiply(mid,n)<(double)m){
            l=mid;
        } else h=mid;
    }
    return l;
}

//O(N*Log(M*(10^d)))-time
//O(1)-space
