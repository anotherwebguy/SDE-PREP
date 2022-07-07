class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	void dfs(int curr, vector<int> adj[], vector<int> &vis, stack<int> &s){
	    vis[curr]=1;
	    for(auto it: adj[curr]){
	        if(!vis[it]) dfs(it,adj,vis,s);
	    }
	    s.push(curr);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> vis(V,0);
	    stack<int> s;
	    vector<int> top;
	    for(int i=0;i<V;i++){
	        if(!vis[i]) dfs(i,adj,vis,s);
	    }
	    while(!s.empty()){
	        top.push_back(s.top());
	        s.pop();
	    }
	    return top;
	}
};

//O(V+E)-time
//O(V)-space
