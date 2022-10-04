/* https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1  */

//Negative weight cycle//

//***************SOLUTION**********/////
//Bellaman Ford algo
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    int dis[n];
	    dis[0]=0;
	    for(int i=1;i<n;i++){
	        dis[i]=INT_MAX;
	    }
	  // Relax all edges |V| - 1 times. A simple
    // shortest path from src to any other vertex can have
    // at-most |V| - 1 edges
	    for(int i=0;i<(n-1);i++){
	        for(auto it:edges){
            //dis[it[0]] !=[INT_MAX] means then node should be relaxed aat least one time.
	            if(dis[it[0]] !=INT_MAX and dis[it[1]]>dis[it[0]]+it[2]){
	                dis[it[1]]=dis[it[0]]+it[2];
	            }
	        }
	    }
	    
	    int sum=accumulate(dis,dis+n,0);

       for(auto it:edges){
            if(dis[it[0]] !=INT_MAX and dis[it[1]]>dis[it[0]]+it[2]){
                dis[it[1]]=dis[it[0]]+it[2];
	            }
	        }
	    
	    int sum1=accumulate(dis,dis+n,0);
	    if(sum==sum1){
	        return 0;
	    }
	    else{
	        return 1;
	    }
	}
};
