//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        // using KAHN ALGORITHM
        
        int indeg[V]={0};
	    for(int i=0;i<V;i++)
	    {
	        for(auto nbr:adj[i]){
	            indeg[nbr]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indeg[i]==0){
	            q.push(i);
	        }
	    }
	    
	    int ct=0;
	    while(!q.empty())
	    {
	        int front=q.front();
	        q.pop();
	        ct++;
	        for(auto nbr:adj[front]){
	            indeg[nbr]--;
	            if(indeg[nbr]==0){
	                q.push(nbr);
	            }
	        }
	        
	    }
	    
	    return ct!=V;       // ct==v means no cycle ans ct!=v means cycle present
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends