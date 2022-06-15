//Approach-1
//O(N*N)-time
//O(N^2)-space

class Solution {
public:
    bool isSafe(int row,int col,int n,vector<string> &b){
          int duprow = row;
          int dupcol = col;

          while (row >= 0 && col >= 0) {
            if (b[row][col] == 'Q')
              return false;
            row--;
            col--;
          }

          col = dupcol;
          row = duprow;
          while (col >= 0) {
            if (b[row][col] == 'Q')
              return false;
            col--;
          }

          row = duprow;
          col = dupcol;
          while (row < n && col >= 0) {
            if (b[row][col] == 'Q')
              return false;
            row++;
            col--;
          }

        return true;
    }
    
    void solve(int col,int n,vector<string> &b, vector<vector<string>> &res){
        if(col==n){
            res.push_back(b);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,n,b)){
                b[row][col]='Q';
                solve(col+1,n,b,res);
                b[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> b(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            b[i]=s;
        }
        solve(0,n,b,res);
        return res;
    }
};

//Approach-2
//O(N*N)-time
//O(N)-space

class Solution {
public:
    void solve(int col,int n,vector<string> &b, vector<vector<string>> &res,vector<int> &left, vector<int> &lower, vector<int> &upper){
        if(col==n){
            res.push_back(b);
            return;
        }
        for(int row=0;row<n;row++){
            if(!left[row] && !lower[row+col] && !upper[n-1+col-row]){
                left[row]=1;
                lower[row+col]=1;
                upper[n-1+col-row]=1;
                b[row][col]='Q';
                solve(col+1,n,b,res,left,lower,upper);
                b[row][col]='.';
                left[row]=0;
                lower[row+col]=0;
                upper[n-1+col-row]=0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> b(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            b[i]=s;
        }
        vector<int> left(n,0), lower(2*n-1,0),upper(2*n-1,0);
        solve(0,n,b,res,left,lower,upper);
        return res;
    }
};
