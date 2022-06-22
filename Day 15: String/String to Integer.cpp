class Solution {
public:
    int myAtoi(string s) {
        int sign=1;
        int res=0;
        int index=0;
        int n=s.size();
        while(index<n && s[index]==' '){
            index++;
        }
        if(index<n && s[index]=='+') {
            sign=1;
            index++;
        }else if(index<n && s[index]=='-'){
            sign=-1;
            index++;
        }
        while(index<n && isdigit(s[index])){
            int digit = s[index]-'0';
            if((res>INT_MAX/10) || (res==INT_MAX/10 && digit>7)){
                return sign==1?INT_MAX:INT_MIN;
            }
            res=res*10+digit;
            index++;
        }
        return sign*res;
    }
};

//O(N)-time
//O(1)-space
