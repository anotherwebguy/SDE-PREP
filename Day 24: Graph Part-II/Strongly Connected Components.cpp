class Solution
{
	public:
	void topodfs(int curr,vector<int> adj[], vector<int> &vis,stack<int> &s){
	    vis[curr]=1;
	    for(auto it : adj[curr]){
	        if(!vis[it]){
	            topodfs(it,adj,vis,s);
	        }
	    }
	    s.push(curr);
	}
	
	void dfs(int curr,vector<int> transpose[], vector<int> &vis){
	    vis[curr]=1;
	    for(auto it : transpose[curr]){
	        if(!vis[it]){
	            dfs(it,transpose,vis);
	        }
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        //step 1
        vector<int> vis(V,0);
        stack<int> s;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                topodfs(i,adj,vis,s);
            }
        }
        
        //step 2
        vector<int> transpose[V];
        for(int i=0;i<V;i++){
            for(auto j : adj[i]){
                transpose[j].push_back(i);
            }
        }
        
        //step 3
        vector<int> visited(V,0);
        int count=0;
        while(!s.empty()){
            int node = s.top();
            s.pop();
            if(!visited[node]){
                dfs(node,transpose,visited);
                count++;
            }
        }
        return count;
    }
};

//O(V+E)-time
//O(V+E)+O(2*N)-space
