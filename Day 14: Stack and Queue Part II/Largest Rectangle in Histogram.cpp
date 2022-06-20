class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n,-1);
        vector<int> right(n,n);
        stack<pair<int,int>> s1,s2;
        for(int i=0;i<n;i++){
            while(!s1.empty() && s1.top().first>=heights[i]) s1.pop();
            if(s1.empty()) left[i]=-1;
            else left[i]=s1.top().second;
            s1.push({heights[i],i});
        }
        for(int i=n-1;i>=0;i--){
            while(!s2.empty() && s2.top().first>=heights[i]) s2.pop();
            if(s2.empty()) right[i]=n;
            else right[i]=s2.top().second;
            s2.push({heights[i],i});
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,heights[i]*(right[i]-left[i]-1));
        }
        return ans;
    }
};

//O(3N)-time
//O(4N)-space
