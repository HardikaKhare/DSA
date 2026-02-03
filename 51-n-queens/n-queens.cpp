class Solution {
public:
 bool check(int row,int col,int n,vector<string>& board){
        int dupr=row,dupc=col;
        while(row >= 0){
            if(board[row][col]=='Q') return false;
            row--;
        }
        row=dupr; col=dupc;
        while(row >= 0 && col < n){
            
            if(board[row][col]=='Q') return false;
            row--;
            col++;
        }
        row=dupr; col=dupc;
        while(row >= 0 && col >= 0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        return true;
    }
    void recursion(int row,int n,vector<vector<string>>& ans,vector<string>& board){
        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){
            if(check(row,col,n,board)){
                board[row][col]='Q';
                recursion(row+1,n,ans,board);
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        recursion(0,n,ans,board);
        return ans;
    }
};