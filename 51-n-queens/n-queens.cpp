class Solution {
public:
 bool check(int row,int col,int n,vector<string>& board){
        int dupr=row,dupc=col;

        // check column upwards
        while(row-1 >= 0){
            row--;
            if(board[row][col]=='Q') return false;
        }

        row=dupr; col=dupc;
        // check upper-right diagonal
        while(row-1 >= 0 && col+1 < n){
            row--;
            col++;
            if(board[row][col]=='Q') return false;
        }

        row=dupr; col=dupc;
        // check upper-left diagonal
        while(row-1 >= 0 && col-1 >= 0){
            row--;
            col--;
            if(board[row][col]=='Q') return false;
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
        vector<string> board(n);
        string s(n,'.');

        for(int i=0;i<n;i++){
            board[i]=s;
        }

        recursion(0,n,ans,board);
        return ans;
    }
};