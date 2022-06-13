// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    int table[V+1];
	    for(int i=0;i<=V;i++) table[i]=INT_MAX;
	    table[0]=0;
	    for(int i=1;i<=V;i++){
	        for(int j=0;j<M;j++){
	            if(coins[j]<=i){
	                int x = table[i-coins[j]];
	                if(x!=INT_MAX && x+1<table[i]){
	                    table[i]=x+1;
	                }
	            }
	        }
	    }
	    if(table[V]==INT_MAX) return -1;
	    else return table[V];
	    //return c;
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends

//O(V*M)-time
//O(V+1)-space
