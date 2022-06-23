//Approach 1
//O(nlogn)-time and O(1)-space
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t) return true;
        else return false;
    }
};

//Approach 2
//O(N)-time & space
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()<t.size())
        {
            return false;
        }
        unordered_map<char,int>freq;
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]]++;
            freq[t[i]]--;
        }
        for(auto x:freq)
        {
            if(x.second!=0)
            {
                return false;
            }
        }
        return true;
    }
};
