#include<bits/stdc++.h>
vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    stack<int> s;
    vector<int> left(n,-1), right(n,n); 
    for(int i=0;i<n;i++){
        while (s.size() && a[s.top()] >= a[i]) s.pop();

        if(s.size()) left[i] = s.top();

        s.push(i);
    }
        
    while (!s.empty()) s.pop();

    for (int i=n-1;i>=0;i--){
        while(!s.empty() && a[s.top()] >= a[i]) s.pop();

        if(s.size()) right[i] = s.top();

        s.push(i);
    }
    vector<int> ans(n+1,INT_MIN);
        
    for (int i=0; i<n; i++){
        int len = right[i] - left[i] - 1;

        ans[len] = max(ans[len], a[i]);
    }

    for (int i=n-1; i>=1; i--)
        ans[i] = max(ans[i], ans[i+1]);

    ans.erase(ans.begin());
    return ans;
}

//O(4*N)-time
//O(N)-space
