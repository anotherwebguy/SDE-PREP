class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(i+1<s.size() && value(s[i])<value(s[i+1])){
                ans+=value(s[i+1])-value(s[i]);
                i++;
            } else ans+=value(s[i]);
        }
        return ans;
    }
    
    int value(char ch){
        switch(ch){
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
        return 0;
    }
};

//O(N)-time
//O(1)-space
