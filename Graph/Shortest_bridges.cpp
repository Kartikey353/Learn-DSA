/*https://leetcode.com/problems/shortest-bridge/ .*/

/*You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.*/

//*******SOLUTION************//

//using FLOOD-FILL algorithm//

class Solution {
public:
//IMP:No visited array required because of line no.21 as we visit the land and we pushed in vector,we convert it into water so automatically it will be not visited again as it is water because of base condition.
    void dfs(int i,int j,vector<vector<int>>& grid,vector<pair<int,int>>&v){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==0){
             return;
        }
        v.push_back({i,j});
        grid[i][j]=0;
 
        dfs(i-1,j,grid,v);
        dfs(i+1,j,grid,v);
        dfs(i,j-1,grid,v);
        dfs(i,j+1,grid,v);
    }
//We pushed 1st island vertex into vector x and 2nd island vertex into vector y,then try to find minimum distance between each coordinates. 
    int shortestBridge(vector<vector<int>>& grid) {
      int count=0;
        vector<pair<int,int>>x,y;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    count++;
//this if-else condition works because as we find first 1 we pushed all coordinates of that island as convert it into water by dfs so if we find second 1 it means that belongs to second island.
                    if(count==1){
                        dfs(i,j,grid,x);
                    }
                    else if(count==2){
                        dfs(i,j,grid,y);
                    }
                }
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<x.size();i++){
            for(int j=0;j<y.size();j++){
             mini=min(mini,abs(x[i].first-y[j].first)+abs(x[i].second-y[j].second) -1 );   
            }
        }
        return mini;
    }
};
