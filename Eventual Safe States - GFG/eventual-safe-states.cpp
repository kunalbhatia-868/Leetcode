//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        //you can reverse all edges by making revAdjand use toposort bfs
        
        vector<int> revAdj[V];
        for(int i=0;i<V;i++)
        {
            for(int nbr: adj[i])
            {
                revAdj[nbr].push_back(i);
            }
        }

        
        vector<int> inDeg(V,0);
        for(int i=0;i<V;i++)
        {
            for(int nbr:revAdj[i]){
                inDeg[nbr]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(inDeg[i]==0){
                q.push(i);
            }
        }
        
        
        // adding all nodes with indeg 0 as they are terminal nodes and thus safe (as indeg=0 means outdeg=0)
        // after the reversal of edges
        // using this while loop rmove them and add their nbr one by one if their indeg is 0
        vector<int> safeNode;
        
        while(!q.empty())
        {
            int fr=q.front();
            q.pop();
            
            for(auto nbr:revAdj[fr]){
                inDeg[nbr]--;
                if(inDeg[nbr]==0){
                    q.push(nbr);
                }
            }
            
            safeNode.push_back(fr);
        }
        sort(safeNode.begin(),safeNode.end());
        return safeNode;
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