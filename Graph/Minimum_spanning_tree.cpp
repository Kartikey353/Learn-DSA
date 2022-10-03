/* https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1 */

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int>parent(V,-1);
        vector<int>key(V,INT_MAX);
        vector<bool>MST(V,false);
        key[0]=0;
        parent[0]=-1;
        for(int count=0;count<V;count++){
         int mini=INT_MAX;
         int u;
         for(int i=0;i<V;i++){
            if(key[i]<mini and MST[i]==false){
                  mini=key[i];
                  u=i;
                }
                  }
            MST[u]=true;
            for(auto j:adj[u]){
                int node=j[0];
                int wt=j[1];
                if(MST[node]==false and key[node]>wt){
                    parent[node]=u;
                    key[node]=wt;
                }
            }
        }
        int sum=0;
    for(int i=0;i<V;i++){
        sum+=key[i];
    }
        return sum;
    }
};
