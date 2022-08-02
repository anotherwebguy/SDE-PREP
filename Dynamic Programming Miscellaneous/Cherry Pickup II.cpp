//Method 1 recurr
class Solution {
public:
    int recurr(int i,int j1,int j2,vector<vector<int>>& grid){
        if(j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size()) return -1e8;
        if(i==grid.size()-1) {
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        int ans=0;
        for( int k = -1;k<=1;k++){
            for(int p = -1;p<=1;p++){
                if(j1==j2) ans = max(ans,grid[i][j1]+recurr(i+1,j1+k,j2+p,grid));
                else ans = max(ans,grid[i][j1]+grid[i][j2]+recurr(i+1,j1+k,j2+p,grid));
            }
        }
        return ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        return recurr(0,0,grid[0].size()-1,grid);
    }
};

//TC:- O(3^n * 3^n)
//SC:- O(N)

//Method 2 memoization
class Solution {
public:
    int dp[100][100][100];
    int recurr(int i,int j1,int j2,vector<vector<int>>& grid){
        if(j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size()) return -1e8;
        if(i==grid.size()-1) {
            if(j1==j2) return dp[i][j1][j2]=grid[i][j1];
            else return dp[i][j1][j2]=grid[i][j1]+grid[i][j2];
        }
        int ans=0;
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        for( int k = -1;k<=1;k++){
            for(int p = -1;p<=1;p++){
                if(j1==j2) ans = max(ans,grid[i][j1]+recurr(i+1,j1+k,j2+p,grid));
                else ans = max(ans,grid[i][j1]+grid[i][j2]+recurr(i+1,j1+k,j2+p,grid));
            }
        }
        return dp[i][j1][j2]=ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return recurr(0,0,grid[0].size()-1,grid);
    }
};

//TC:- O(N*M*M)*9
//SC:- O(N*M*M)+O(N)

