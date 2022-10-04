/* https://leetcode.com/problems/01-matrix/*/


/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.
*/
//************SOLUTION****************//

//**** for shortest distance think for bfs before dfs******////
class Solution {
public:
    bool isValid(int i,int j,vector<vector<int>>&mat){
        if(i<0 || j<0 || i>=mat.size() || j>=mat[i].size()){
            return false;
        }
        return true;
    }
    
    void dis(queue<pair<int,int>>&q,vector<vector<int>>&mat){
//queue contains all coordinate of zeroes.
      while(!q.empty()){
               int size=q.size();
            for(int i=0;i<size;i++){
               int x=q.front().first;
               int y=q.front().second;
               q.pop();
//we have converted all 1 to -1 because then mat can act as visited also,not to 0 because then it can confuse to insert in queue or not.
              if(isValid(x+1,y,mat) and mat[x+1][y]==-1){
                     mat[x+1][y]=mat[x][y]+1;//this means mat[x][y] is number of steps to reach 0 from (x,y) then for (x+1,y) will be 1+ mat[x][y],similarily for all.
                      q.push({x+1,y});
                  }
                if(isValid(x-1,y,mat) and mat[x-1][y]==-1){
                     mat[x-1][y]=mat[x][y]+1;
                      q.push({x-1,y});
                  }
                if(isValid(x,y+1,mat) and mat[x][y+1]==-1){
                     mat[x][y+1]=mat[x][y]+1;
                      q.push({x,y+1});
                  }
                if(isValid(x,y-1,mat) and mat[x][y-1]==-1){
                     mat[x][y-1]=mat[x][y]+1;
                      q.push({x,y-1});
                  }
                
         }
    }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//all one       
      
        queue<pair<int,int>>q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
                else{
                    mat[i][j]=-1;
                }
            }
        }
        dis(q,mat);
 return  mat;
    }
};
