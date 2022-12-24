//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // detect cycle in a directed graph
    
    bool dfs(vector<int> adj[],int src,int vis[],int pathVis[],int safeNodes[]){
        vis[src]=1;
        pathVis[src]=1;
        
        for(int nbr:adj[src])
        {
            if(!vis[nbr]){
                if(dfs(adj,nbr,vis,pathVis,safeNodes)==true){
                    safeNodes[src]=0;
                    return true;
                }
            }
            else if(pathVis[nbr]){
                safeNodes[src]=0;
                return true;
            }
        }
        
        safeNodes[src]=1;
        pathVis[src]=0;
        return false;
    }
    
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0};
        int pathVis[V]={0};
        int safeNodes[V]={0};
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(adj,i,vis,pathVis,safeNodes);
            }
        }
        
        vector<int> output;
        for(int i=0;i<V;i++){
            if(safeNodes[i]==1){
                output.push_back(i);
            }
        }
        return output;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends