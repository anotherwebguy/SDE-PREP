class Solution
{
	public:
	struct tree{
	    int a;
	    int b;
	    int w;
	};
	
	static bool comp(tree a,tree b){
	    return a.w<b.w;
	}
    
    int findPar(int node,vector<int> &parent){
        if(node==parent[node]) return node;
        return parent[node]=findPar(parent[node],parent);
    }
    
    void Union(int x, int y, vector<int> &parent, vector<int> &rank){
        int u = findPar(x,parent);
        int v = findPar(y,parent);
        if(rank[u]<rank[v]){
            parent[u]=v;
        } else if(rank[u]>rank[v]){
            parent[v]=u;
        } else {
            parent[v]=u;
            rank[u]++;
        }
    }
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int res=0;
        vector<tree>g;
        vector<int> parent(V);
        vector<int> rank(V);
        for(int i=0;i<V;i++){
            parent[i]=i;
            rank[i]=0;
        }
        for(int i=0;i<V;i++){
            for(vector<int>p:adj[i]){
                tree temp;
                temp.a=i;
                temp.b=p[0];
                temp.w=p[1];
                g.push_back(temp);
            }
        }
        sort(g.begin(),g.end(),comp);
        for(int i=0;i<g.size();i++){
            if(findPar(g[i].a,parent)!=findPar(g[i].b,parent)){
                res+=g[i].w;
                Union(g[i].a,g[i].b,parent,rank);
            }
        }
        return res;
        
    }
};

//Using Union Find algo
//O(MlogM)-time
//O(4*N)-space
