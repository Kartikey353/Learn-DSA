/*https://leetcode.com/problems/rotting-oranges/ */

/*You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.*/


class Solution {
public:
//Using BFS
    int bfs(vector<vector<int>>& grid,queue<pair<int,int>>&q){
        int cnt=0;//time
        while(!q.empty()){
            cnt++;             //all 2 will active simultaneously so when all rotten will do first layer then increment.
            int size=q.size(); //before this we have pushed all coordinate having rotten oranges(2)
            for(int k=0;k<size;k++){
                pair<int,int>top=q.front();
                int i=top.first;
                int j=top.second;
                q.pop();
                if(i-1>=0 and grid[i-1][j]==1){
                    q.push({i-1,j});grid[i-1][j]=2;
                }
                if(i+1<grid.size() and grid[i+1][j]==1){
                    q.push({i+1,j});grid[i+1][j]=2;
                }
                if(j-1>=0 and grid[i][j-1]==1){
                    q.push({i,j-1});grid[i][j-1]=2;
                }
                if(j+1<grid[i].size() and grid[i][j+1]==1){
                    q.push({i,j+1});grid[i][j+1]=2;
            }
            }
        }
        if(cnt==0){
            //when we have all 0 or when all are 2 and for all 1 later it is checked in line 57,58,59
            return 0;
        }
        return cnt-1;
    }
    
    
    int orangesRotting(vector<vector<int>>& grid) {
      
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        
int ans=bfs(grid,q);
for(int i=0;i<grid.size();i++){
    for(int j=0;j<grid[i].size();j++){
        if(grid[i][j]==1){
            //any 1(fresh orange) left after calling of bfs or all are 1.
            return -1;
        }
    }
}

        return ans;
    }
};
