// 51. N-Queens(All possible permutation)

// fill column-wise

class Solution {
public:
    bool IsSafe(vector<string>&cur,int row,int col,int n)
    {
     // Check in Row
     for(int i=0;i<col;i++)
     {
      if(cur[row][i]=='Q')
          return true;
     }
     
     // Check in upper left diagonal
     
     int i=row,j=col;
     while(i>=0 && j>=0)
     {
      if(cur[i][j]=='Q')
          return true;
      i--;
      j--;
     }
     
     // Check in lower left diagonal
        
     i=row;
     j=col;
     while(i<n && j>=0)
     {
      if(cur[i][j]=='Q')
          return true;
      i++;
      j--;
     }
        
     return false; // It's safe
     
    }
    
    void doit(vector<vector<string>>&ans,vector<string>&cur,int col,int n)
    {
     if(col>=n)
     {
      ans.push_back(cur);
      return;
     }
     for(int row=0;row<n;row++)
     {
      if(!IsSafe(cur,row,col,n))
      {
       cur[row][col]='Q';
       doit(ans,cur,col+1,n);
       cur[row][col]='.';
      }
     }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
     vector<vector<string>>ans;
     vector<string>cur(n,string(n,'.'));
     if(n==0)
         return ans;
     doit(ans,cur,0,n);
     return ans;
        
    }
};

// 52. N-Queens II(count total permutation)

class Solution {
public:
    int ans;
    bool IsSafe(vector<string>&cur,int row,int col,int n)
    {
     for(int i=0;i<col;i++)
     {
      if(cur[row][i]=='Q')
          return true;
     }
     int i=row,j=col;
     while(i>=0 && j>=0)
     {
      if(cur[i][j]=='Q')
          return true;
      i--;
      j--;
     }
     i=row;j=col;
     while(i<n && j>=0)
     {
       if(cur[i][j]=='Q')
          return true;
      i++;
      j--;
     }
     return false;
    }
    void doit(vector<string>&cur,int col,int n)
    {
     if(col>=n)
     {
      ans++;
      return;
     }
     for(int row=0;row<n;row++)
     {
      if(!IsSafe(cur,row,col,n))
      {
       cur[row][col]='Q';
       doit(cur,col+1,n);
       cur[row][col]='.';
      }
     }
    }
    int totalNQueens(int n) 
    {
     if(n==0)
         return 0;
     ans=0;
     vector<string>cur(n,string(n,'.'));
     doit(cur,0,n);
     return ans;
    }
};
