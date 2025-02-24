class Solution {
    public double myPow(double x, int n) {
        double ans = 1.0;
        int f = 0;
        long nn = n;
        if(n<0) {
            f = 1;
            nn = -1L * n;
        }
        while(nn>0){
            if(nn%2==1){
                ans *= (double)x;
                nn--;
            } else {
                x *= x;
                nn /= 2;
            }
        }
        if(f==1) ans = (double)(1.0)/(double)(ans);
        return ans;
    }
}


//O(logN)- time
