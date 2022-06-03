class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        int f=0;
        long long nn=n;
        if(n<0) {
            f=1;
            nn=abs(n);
        }
        //n*=(-1);
        while(nn>0){
            if(nn%2){
                ans*=(double)x;
                nn--;
            } else {
                x*=x;
                nn/=2;
            }
        }
        if(f) ans=(double)(1.0)/(double)ans;
        return ans;
    }
};

// O(logn)-time
// O(1)-space
