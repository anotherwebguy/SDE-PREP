class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prev = image[sr][sc];
        if(color!=prev) dfs(image,sr,sc,color,prev);
        return image;
    }
    
    void dfs(vector<vector<int>> &image,int sr,int sc,int color,int prev){
        if(image[sr][sc]==prev){
            image[sr][sc]=color;
            if(sr>=1) dfs(image,sr-1,sc,color,prev);
            if(sc>=1) dfs(image,sr,sc-1,color,prev);
            if(sr+1<image.size()) dfs(image,sr+1,sc,color,prev);
            if(sc+1<image[0].size()) dfs(image,sr,sc+1,color,prev);
        }
    }
};

//O(N)-time &space
