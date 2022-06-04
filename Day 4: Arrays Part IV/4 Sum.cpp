class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        sort(a.begin(),a.end());
        vector<vector<int>> res;
        for(int i=0;i<a.size();i++){
            for(int j=i+1;j<a.size();j++){
                int nt=target-a[i]-a[j];
                int l=j+1,h=a.size()-1;
                while(l<h){
                    if(a[l]+a[h]==nt){
                        vector<int> temp;
                        temp.push_back(a[i]);
                        temp.push_back(a[j]);
                        temp.push_back(a[l]);
                        temp.push_back(a[h]);
                        if(find(res.begin(),res.end(),temp)==res.end()) res.push_back(temp);
                        l++;
                        h--;
                        while(l<h && a[l]==a[l-1]) l++;
                        while(l<h && a[h]==a[h+1]) h--;
                    } else if(a[l]+a[h]<nt) l++;
                    else h--;
                }
                while(j+1<a.size() && a[j+1]==a[j]) j++;
            }
            while(i+1<a.size() && a[i+1]==a[i]) i++;
        }
        return res;
    }
};

// O(N^3)-time
// O(1)-space
