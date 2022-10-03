/*https://practice.geeksforgeeks.org/problems/mother-vertex/1 */

/*Given a Directed Graph, find a Mother Vertex in the Graph (if present). 
A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.*/

///*********solution***********//////////

//Approach:If there is path from u->v then u always come before v and u will be a mother vertex,so same approach  of toposort to find last finished vertex.We will get st.top() then check it for mother vertex if yes then st.top() else -1.

class Solution 
{
void dfs(int src,int V,vector<int>adj[],int visited[],stack<int>&st){
        visited[src]=1;
        for(auto it:adj[src]){
            if(visited[it]){
                continue;
            }
            dfs(it,V,adj,visited,st);
        }
        st.push(src);
    }
    
    public:
    //Function to find a Mother Vertex in the Graph.

	int findMotherVertex(int V, vector<int>adj[])
	{
	   int visited[V];
	   for(int i=0;i<V;i++){
	       visited[i]=0;
	   }
	   stack<int>st;
	   for(int i=0;i<V;i++){
	       if(visited[i]==1){
	           continue;
	       }
	       else{
	       dfs(i,V,adj,visited,st);
	   }
	   }
	   for(int i=0;i<V;i++){
	       visited[i]=0;
	   }

	   int first=st.top();
	   
	   dfs(first,V,adj,visited,st);

	   for(int i=0;i<V;i++){
	       if(visited[i]==0){
	           return -1;
	       }
	   }
	    return first;
	}

};
