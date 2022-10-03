
#include <bits/stdc++.h>
using namespace std;

void bfs(int **edges,int n,int s,int*visited){
    queue<int>q;
  // Pushed source in a queue.
    q.push(s);
    while(!q.empty()){
        int top=q.front();
        q.pop();
        visited[s]=1;
        cout<<top<<" ";
        for(int i=0;i<n;i++){
          //iterating over connected nodes of source.  
          if(i==top){
                continue;
            }
          // if there is an edge between source and node and the node is not visited then visit it and push it in queue.
            if(edges[top][i]==1 and !visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}

// time complexity->O(n+e)
//Space complexity->O(n)

int main() {
  /*creating a undirected graph with n nodes and e edges*/
    int n,e;
    cin>>n>>e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
   // Visited array is important because it tell which nodes we have visited so that we do not trap in cycle.
    int *visited=new int[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
 }
  //  this for loop is for unconnected graph,for loop allows to visit each component of graph.
    for(int i=0;i<n;i++){
      if(!visited[i])
      {bfs(edges,n,i,visited);      
    }
    }
}
