//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int> adj[],int src,int vis[],int pathVis[]) {
        vis[src]=1;
        pathVis[src]=1;
        
        for(int nbr:adj[src]){
            if(!vis[nbr]){
                if(dfs(adj,nbr,vis,pathVis)==true){       // cycle found in this nbr
                    return true;
                }
            }
            else if(pathVis[nbr]){
                return true;
            }
        }
        
        pathVis[src]=0;                     // this path checked not found check another one
        return false;
        
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0};
        int pathVis[V]={0};
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(adj,i,vis,pathVis)==true){       // cycle found in this comp
                    return true;
                }
            }
        }
        
        return false;
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