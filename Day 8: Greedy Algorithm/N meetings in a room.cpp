// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    bool static comparator(pair<int,pair<int,int>> &a1, pair<int,pair<int,int>> &a2){
        if(a1.second.first<a2.second.first) return true;
        else if(a1.second.first>a2.second.first) return false;
        else if(a1.second.second<a2.second.second) return true;
        else return false;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,pair<int,int>>> m;
        for(int i=0;i<n;i++){
            m.push_back({start[i],{end[i],i+1}});
        }
        sort(m.begin(),m.end(),comparator);
        int c=1,last=m[0].second.first;
        for(int i=1;i<n;i++){
            if(m[i].first>last){
                c++;
                last=m[i].second.first;
            }
        }
        return c;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends

//O(N)+O(nlogn)+O(N)-time
//O(N)-space

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    bool static comparator(pair<int,int> a, pair<int,int> b){
        if(a.second<b.second) return true;
        else if(a.second>b.second) return false;
        else return false;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> ds;
        for(int i=0;i<n;i++){
            ds.push_back(make_pair(start[i],end[i]));
        }
        sort(ds.begin(),ds.end(),comparator);
        int cnt = 1, last = ds[0].second;
        for(int i=1;i<n;i++){
            if(last<ds[i].first){
                cnt++;
                last = ds[i].second;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
