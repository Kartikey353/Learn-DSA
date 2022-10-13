/*
find the shortest dist from the given source node to every other node
Approach : make the dist[src] = 0, now start traversing using BFS and the distance of adjace node
will be dist[curr node] + 1.
T : O(n + e)
S : O(n) + O(n)
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    /*
    9 11 5
    0 1
    0 3
    1 3
    1 2
    3 4
    4 5
    5 6
    2 6
    6 7
    7 8
    6 8
    */
    int n,m,src; cin>>n>>m>>src;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dist(n,INT_MAX);
    dist[src] = 0;//distance of source from source will be 0
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it:adj[node]){
            int curr = dist[node] + 1;
            if(curr < dist[it]){//if dist from present node will be less then previous stored dist
                dist[it] = curr;
                q.push(it);
            }
        
        }
    }
    for(int i=0;i<n;i++){
        cout<<src<<"-"<<i<<"="<<dist[i]<<endl;
    }
    return 0;
}