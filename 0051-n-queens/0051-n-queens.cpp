class Solution {
public:
    bool isSafe(vector<string>& chess,int row,int col)
    {
      // row
      for(int i=0;i<col;i++)
      {
        if(chess[row][i]=='Q')
        {
          return false;
        }
      }

      // col
      for(int i=0;i<row;i++)
      {
        if(chess[i][col]=='Q')
        {
          return false;
        }
      }

      // diagonal
      for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
      {
        if(chess[i][j]=='Q')
        {
          return false;
        }
      }

      for(int i=row-1,j=col+1;i>=0 && j<chess.size();i--,j++)
      {
        if(chess[i][j]=='Q')
        {
          return false;
        }
      }

    return true;

}
    void solve(vector<string>& board,int row,vector<vector<string>>& output)
    {
        int n=board.size();
        if(row==n){
            output.push_back(board);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(isSafe(board,row,i))
            {
                board[row][i]='Q';
                solve(board,row+1,output);
                board[row][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> output;
        vector<string> board;
        for(int i=0; i<n; i++){
            string temp="";
            for(int j=0; j<n; j++){
                temp+= '.';
            }
            board.push_back(temp);
        }
        
        solve(board,0,output);
        return output;
    }
};