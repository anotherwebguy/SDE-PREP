class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int res=0;
        vector<int> key(V,INT_MAX);
        vector<bool> mst(V,false);
        vector<int> parent(V,-1);
        key[0]=0;
        for(int i=0;i<V;i++){
            int mini=INT_MAX,u=0;
            for(int j=0;j<key.size();j++){
                if(key[j]<mini && mst[j]==false){
                    mini=key[j];
                    u=j;
                }
            }
            mst[u]=true;
            res+=key[u];
            for(auto it : adj[u]){
                if(!mst[it[0]] && it[1]<key[it[0]]){
                    key[it[0]]=it[1];
                    parent[it[0]] = u;
                }
            }
        }
        return res;
    }
};

//O(N^2)-time
//O(3*N)-space
