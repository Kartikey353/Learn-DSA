/*TOPOSORT using DFS */

class Solution
{
	public:
//We will insert a element after it's dfs call is over.
void dfs(int start,int V, vector<int> adj[],stack<int>&st,vector<int>&visited){
    visited[start]=1;
    for(int i=0;i<adj[start].size();i++){
       if(!visited[adj[start][i]]){ 
         dfs(adj[start][i],V,adj,st,visited);}
    }
    st.push(start);
}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{   vector<int>visited(V,0);
	    stack<int>st;
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            dfs(i,V,adj,st,visited);
	        }
	    }
	    vector<int>ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};

/* TOPOSORT using BFS*/


#include <bits/stdc++.h>
using namespace std;


class Solution
{
	public:

void check(queue<int>&q,vector<int>&indegree){
	    for(int i=0;i<indegree.size();i++){
	        if(indegree[i]==0){q.push(i);}
	    }
	}
	
	vector<int>bfs(int V, vector<int> adj[],vector<int>&indegree){
	    queue<int>q;
	    check(q,indegree);
	    vector<int>topo;
	    while(!q.empty()){
	        int top=q.front();
	        topo.push_back(top);
	        q.pop();
	        for(int i=0;i<adj[top].size();i++){
	            indegree[adj[top][i]]--;
	            if(indegree[adj[top][i]]==0){q.push(adj[top][i]);}
	        }
	    }
	    return topo;
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   vector<int>indegree(V);
	   for(int i=0;i<V;i++){
	       for(int j=0;j<adj[i].size();j++){
	           indegree[adj[i][j]]++;
	       }
	   }
	   vector<int>ans=bfs(V,adj,indegree);
	   return ans;
	}
};
