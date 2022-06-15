class Solution {
public:
    bool isSafe(int r,int c,char k,vector<vector<char>> &board){
        for(int i=0;i<board.size();i++){
            if(board[r][i]==k) return false;
            if(board[i][c]==k) return false;
            if(board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == k)
      return false;

        }
        return true;
    }
    
    bool solve(vector<vector<char>> &board){
        for(int r=0;r<board.size();r++){
            for(int c=0;c<board[0].size();c++){
                if(board[r][c]=='.'){
                    for(char k='1';k<='9';k++){
                        if(isSafe(r,c,k,board)){
                            board[r][c]=k;
                            if(solve(board)) return true;
                            else board[r][c]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

//O(9^(n^2))-time
//O(1)-space
