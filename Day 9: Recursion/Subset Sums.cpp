// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

    void solve(int ind,vector<int> arr,vector<int> &res,int sum, int n){
        if(ind>=n){
            res.push_back(sum);
            return;
        }
        sum+=arr[ind];
        solve(ind+1,arr,res,sum,n);
        sum-=arr[ind];
        solve(ind+1,arr,res,sum,n);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        int sum=0;
        vector<int> res;
        solve(0,arr,res,sum,N);
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends

//O(2^N)-time
//O(2^N)-space
