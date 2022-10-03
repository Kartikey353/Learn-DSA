#include <bits/stdc++.h>
using namespace std;


// function for dfs
void dfs(vector<vector<int>>adj,int s,bool visited[]) {
  //mark source as visited.      
  visited[s] = true;
  cout<<s<<" "; 
  //iterate in connected nodes of source.      
  for(int i = 0;i < adj[s].size();++i)    {
     //if particular node is not visited then call for dfs on that node.
         if(visited[adj[s][i]] == false)
             dfs(adj,adj[s][i],visited);
        }
    }
int main(){
 
  //create a graph same as in bfs.
  //visited array.
  //call dfs on each component of graph.
  
return 0;}
