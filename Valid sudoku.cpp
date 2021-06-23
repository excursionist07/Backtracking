// 37. Sudoku Solver

#define N 9
/*
Time complexity: O(9^(n*n)).
For every unassigned index there are 9 possible options so the time complexity is O(9^(n*n)).
Space Complexity: O(n*n).
To store the output array a matrix is needed.
*/

class Solution {
public:
    bool UnsignedCell(vector<vector<char>>& board,int& row,int& col)
    {
     for(row=0;row<N;row++)
     {
      for(col=0;col<N;col++)
      {
       if(board[row][col]=='.')
         return true; 
      }
     }
     return false;
    }
    
    
    bool CheckInRow(vector<vector<char>>& board,char num,int row)
    {
     for(int col=0;col<N;col++)
     {
      if(board[row][col]==num)
          return true;
     }
     return false;
    }
    
    bool CheckInCol(vector<vector<char>>& board,char num,int col)
    {
     for(int row=0;row<N;row++)
     {
      if(board[row][col]==num)
          return true;
     }
     return false;
    }
    
     bool CheckInBox(vector<vector<char>>& board,char num,int boxstartrow,int boxstartcol)
    {
     for(int row=0;row<3;row++)
     {
      for(int col=0;col<3;col++)
      {
       if(board[row+boxstartrow][col+boxstartcol]==num)
          return true;
      }
     }
     return false;
    }
    
    bool IsSafe(vector<vector<char>>& board,char num,int row,int col)
    {
     return (!CheckInRow(board,num,row) && !CheckInCol(board,num,col) && !CheckInBox(board,num,row-row%3,col-col%3));
    }
    
    
   
    
    
    bool solve(vector<vector<char>>& board)
    {
     int row,col;
     if(!UnsignedCell(board,row,col))
         return true;
     for(char ch='1';ch<='9';ch++)
     {
      if(IsSafe(board,ch,row,col))
      {
       board[row][col]=ch;
       if(solve(board))
           return true;
       board[row][col]='.'; // bacaktrack if not possible
      }
     }
     return false;
    }
    
    
    void solveSudoku(vector<vector<char>>& board) 
    {

     if(solve(board))
      return;
    }
};


// 36. Valid Sudoku

class Solution {
public:
    bool CheckInRow(vector<vector<char>>& board,char num,int row)
    {
     int cnt=0;
     for(int col=0;col<9;col++)
     {
      if(board[row][col]==num)
          cnt++;
     }
     return (cnt!=1);
    }

    bool CheckInCol(vector<vector<char>>& board,char num,int col)
    {
     int cnt=0;
     for(int row=0;row<9;row++)
     {
      if(board[row][col]==num)
         cnt++;
     }
     return (cnt!=1);
    }

     bool CheckInBox(vector<vector<char>>& board,char num,int boxstartrow,int boxstartcol)
    {
     int cnt=0;
     for(int row=0;row<3;row++)
     {
      for(int col=0;col<3;col++)
      {
       if(board[row+boxstartrow][col+boxstartcol]==num)
          cnt++;
      }
     }
      return (cnt!=1);
    }

    bool IsSafe(vector<vector<char>>& board,char num,int row,int col)
    {
     return (CheckInRow(board,num,row) || CheckInCol(board,num,col) || CheckInBox(board,num,row-row%3,col-col%3));
    }







    bool isValidSudoku(vector<vector<char>>& board)
    {
     for(int i=0;i<board.size();i++)
     {
      for(int j=0;j<board[i].size();j++)
      {
       if(board[i][j]!='.' && IsSafe(board,board[i][j],i,j))
           return false;
      }
     }
        return true;
    }
};
