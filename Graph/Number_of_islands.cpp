/*https://leetcode.com/problems/number-of-islands/submissions/ */

class Solution {
public:
  void  dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>&visited){
         visited[i][j]=1;
          if(i+1<grid.size() and grid[i+1][j]=='1' and !visited[i+1][j]){
              dfs(i+1,j,grid,visited);
          }
          if(i-1>=0 and grid[i-1][j]=='1' and !visited[i-1][j]){
              dfs(i-1,j,grid,visited);
          }
          if(j+1<grid[0].size() and grid[i][j+1]=='1' and !visited[i][j+1]){
              dfs(i,j+1,grid,visited);
          }
          if(j-1>=0 and grid[i][j-1]=='1' and !visited[i][j-1]){
              dfs(i,j-1,grid,visited);
          }
    }
    
    
    
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        int columns=grid[0].size();
         vector<vector<int>>visited(rows);
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                visited[i].push_back(0);
            }
        }
        int cnt=0;
       for(int i=0;i<rows;i++){
           for(int j=0;j<columns;j++){
               if(grid[i][j]=='1' and !visited[i][j]){
                   cnt++;
                   dfs(i,j,grid,visited);
               }
           }
       }
    return cnt;}
};
