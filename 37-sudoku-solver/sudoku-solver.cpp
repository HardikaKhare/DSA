class Solution {
public:
    bool possible(vector<vector<char>>& board,char digit,int i,int j){
        for(int m=0;m<9;m++){
            if(digit==board[i][m]) return false;
        }
        for(int n=0;n<9;n++){
            if(digit==board[n][j]) return false;
        }
        for(int s=(i/3)*3;s<((i/3)*3)+3;s++){
            for(int t=(j/3)*3;t<((j/3)*3)+3;t++){
                if(digit==board[s][t]) return false;
            }
        }
        return true;
    }
    bool recurse(vector<vector<char>>& board,int row,int col){
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]!='.') continue;
                for(int num=1;num<=9;num++){
                    char digit='0'+num;
                    if(possible(board,digit,i,j)){
                         board[i][j]=digit;
                         if(recurse(board,row,col)) return true;
                         else board[i][j]='.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int row=board.size();
        int col=board[0].size();
        recurse(board,row,col);
    }
};