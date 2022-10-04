/*https://leetcode.com/problems/as-far-from-land-as-possible/ */

//Important-> this uses concept of multiple bfs.

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int res = 0;
        queue<pair<int,int>> q;
        
        //find all lands and add them to q (as start points of the bfs)
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid.size(); j++)
                if (grid[i][j] == 1)
                    q.push({i,j});
            
        //start bfs (second step)
        while(!q.empty()){
            pair<int,int> curr= q.front();
            q.pop();
            
            //4 directions
            vector<pair<int,int>> dirs {{0,1},{0,-1},{1,0},{-1,0}};
            
            //check for 4 directions
            for (auto dir : dirs){
                int i = curr.first + dir.first;
                int j = curr.second + dir.second;
                
                //avoid getting i and j outside the grid && check if grid[i][j] == 0
                if (i >= 0 && i < grid.size() && j >= 0 && j < grid.size() && grid[i][j] == 0){
                    grid[i][j] = grid[curr.first][curr.second] + 1;
                    q.push({i,j});
                    res = max(res,grid[i][j]);
                }
            }

        }
        
        return res - 1;        
    }
};
