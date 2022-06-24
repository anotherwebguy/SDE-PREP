class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0;
        int x=0,y=0;
        version1+='.';
        version2+='.';
        int n=version1.size(),m=version2.size();
        while(i<n && j<m){
            if(version1[i]=='.' && version2[j]=='.'){
                if(x<y) return -1;
                else if(x>y) return 1;
                x=0;
                y=0;
                i++;
                j++;
                if(i==n || j==m) break;
            }
            if(version1[i]!='.'){
                x = x*10 + (version1[i]-'0');
                i++;
            }
            if(version2[j]!='.'){
                y = y*10 + (version2[j]-'0');
                j++;
            }
        }
        if(i<n) {
            while(i<n){
                if(version1[i]!='0' && version1[i]!='.') return 1;
                i++;
            }
        }
        if(j<m) {
            while(j<m){
                if(version2[j]!='0' && version2[j]!='.') return -1;
                j++;
            }
        }
        return 0;
    }
};

//O(max(n,m)-time
//O(1)-space
