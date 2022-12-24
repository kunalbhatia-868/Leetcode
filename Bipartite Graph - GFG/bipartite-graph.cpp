//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool isBipartiteComponent(vector<int>adj[],int src,vector<int>& color)
    {
        queue<int> q;
        
        color[src]=0;     // starting node as first color
        q.push(src);      // add start node to queue

        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            
            int nbrColor=color[front]==0?1:0;
            for(int nbr:adj[front]){
                if(color[nbr]==-1){         //nbr is colorless
                    color[nbr]=nbrColor;    //color is with opp color and push in q
                    q.push(nbr);
                    
                }
                else if(color[nbr]==color[front]){            //same color as adjacent
                    return false;
                }
                //else if nbr is colored with color is diff to us we are fine with it
            }
        }
        return true;
    }   
    
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V,-1);        // -1 mean colorless, (0,1) two colors 
        
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(isBipartiteComponent(adj,i,color)==false){       // if any comp ans is false
                    return false;
                }
            }
        }
        //if all comp are true
        return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends