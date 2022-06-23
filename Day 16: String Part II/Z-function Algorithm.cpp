class Solution {
public:
    vector<int> computeZ(string str){
        int n = str.size();
        int left=0,right=0;
        vector<int> z(n,0);
        for(int k=1;k<n;k++){
            if(k>right){ //outside box
                left=right=k;
                while(right<n && str[right]==str[right-left]) right++;
                z[k]=right-left;
                right--; //since right will become 1 greater
            } else {
                int start = k-left;
                if(z[start]+k-1<right){
                    z[k]=z[start]; //within right bound condition
                } else {
                    left=k;
                    while(right<n && str[right]==str[right-left]) right++;
                    z[k]=right-left;
                    right--;
                }
            }
        }
        return z;
    }
    
    int strStr(string haystack, string needle) {
        string str = needle+'$'+haystack;
        vector<int> z = computeZ(str);
        for(int i=0;i<z.size();i++){
            if(z[i]==needle.size()) return i-needle.size()-1;
        }
        return -1;
    }
};

//O(m+n)-time and space
