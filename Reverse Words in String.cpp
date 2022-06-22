//Approach 1-stringstream O(N)-both
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> v;
        while(ss>>word){
            v.push_back(word);
        }
        reverse(v.begin(),v.end());
        string res="";
        for(int i=0;i<v.size();i++){
            if(i!=v.size()-1) res+=v[i]+" ";
            else res+=v[i];
        }
        return res;
    }
};

//Apporach 2-stacks O(N)-both
class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string k="";
        s+=" ";
        for(int i=0;i<s.size();i++){
            if(s[i]==' ' && k==""){
                continue;
            }else if(s[i]==' '){
                st.push(k);
                k="";
            }else k+=s[i];
        }
        string res="";
        while(st.size()!=1){
            res+=st.top()+" ";
            st.pop();
        }
        res+=st.top();
        return res;
    }
};

//Approach 3 O(N)-time O(1)-space
class Solution {
public:
    string reverseWords(string s) {
        string k="";
        s+=" ";
        string res="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' ' && k==""){
                continue;
            }else if(s[i]==' '){
                if(res=="") res=k;
                else res=k+" "+res;
                k="";
            }else k+=s[i];
        }
        return res;
    }
};
