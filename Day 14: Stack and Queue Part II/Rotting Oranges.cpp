class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int tot=0,cnt=0,time=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]) tot++;
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        while(!q.empty()){
            int k = q.size();
            cnt+=k;
            while(k--){
                int x = q.front().first,y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx = x+dx[i],ny=y+dy[i];
                    if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size() && grid[nx][ny]==1) {
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                    }
                }
            }
            if(!q.empty()) time++;
        }
        return tot==cnt? time:-1;
    }
};

//O(nxnx4)-time
//O(nxm)-space
//bfs approach
