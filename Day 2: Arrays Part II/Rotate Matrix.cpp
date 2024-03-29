class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<matrix.size();i++){
            vector<int> t = matrix[i];
            reverse(t.begin(),t.end());
            matrix[i]=t;
        }
    }
};


/*
  2*O(N^2)-Time approach
  O(1)-Space 
*/
