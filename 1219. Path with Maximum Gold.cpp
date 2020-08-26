int dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
class Solution {
public:
    int dfs(vector<vector<int>>&grid,int x,int y)
    {
     int res=0;
     int temp=grid[x][y];
     grid[x][y]=0;
     for(int i=0;i<4;i++)
     {
      int xx=x+dir[i][0];
      int yy=y+dir[i][1];
      if(xx>=0 && xx<grid.size() && yy>=0 && yy<grid[x].size() && grid[xx][yy]!=0)
      {
       res=max(res,grid[xx][yy]+dfs(grid,xx,yy));
      }
     }
     grid[x][y]=temp;
     return res;
    }
    int getMaximumGold(vector<vector<int>>& grid)
    {
     int res=0;
     for(int i=0;i<grid.size();i++)
     {
      for(int j=0;j<grid[i].size();j++)
      {
       if(grid[i][j]>0)
           res=max(res,grid[i][j]+dfs(grid,i,j));
      }
     }
     return res;
    }
};
