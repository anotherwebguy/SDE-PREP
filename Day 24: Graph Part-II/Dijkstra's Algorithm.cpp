class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dis(V,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,S});
        dis[S]=0;
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            for(auto it: adj[t.second]){
                if(dis[t.second]+it[1]<dis[it[0]]){
                    dis[it[0]]=dis[t.second]+it[1];
                    pq.push({dis[it[0]],it[0]});
                }
            }
        }
        return dis;
    }
};
//O(N+E)logN-time
//O(2*N)-space
