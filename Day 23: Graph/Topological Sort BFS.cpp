class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> indegree(V,0);
	    vector<int> top;
        for(int i=0;i<V;i++){
            for(auto j : adj[i]) indegree[j]++;
        }
        queue<int> q;
        for(int i=0;i<V;i++) if(!indegree[i]) q.push(i);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            top.push_back(x);
            for(auto it:adj[x]){
                indegree[it]--;
                if(indegree[it]==0) {
                    q.push(it);
                }
            }
        }
        return top;
	}
};

//O(V+E)-time
//O(V)-space
