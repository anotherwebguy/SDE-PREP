int count(vector<int> &A,int x){
    int l=0,h=A.size()-1;
    while(l<=h){
        int m = l+(h-l)/2;
        if(A[m]<=x) l=m+1;
        else h=m-1;
    }
    return l;
}

int Solution::findMedian(vector<vector<int> > &A) {
    int l=1,h=1e9;
    int n = A.size(),m=A[0].size();
    int x = (n*m)/2;
    while(l<=h){
        int m = l+(h-l)/2;
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=count(A[i],m);
        }
        if(cnt<=x) l=m+1;
        else h=m-1;
    }
    return l;
}


//O(Log(2^32)xNxLog(M))-time
//O(1)-space
