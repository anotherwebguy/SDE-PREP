class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    for(int k=0;k<matrix.size();k++){
	        for(int i=0;i<matrix.size();i++){
	            for(int j=0;j<matrix[0].size();j++){
	                if(matrix[i][k]==-1 || matrix[k][j]==-1) continue;
	                if(matrix[i][j]==-1) matrix[i][j]=matrix[i][k]+matrix[k][j];
	                else matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }
	}
};

//O(V^3)-time
//O(V^2)-space
