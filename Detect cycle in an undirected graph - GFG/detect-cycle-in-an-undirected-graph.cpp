//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool checkCycle(vector<int> adj[],int node,int V,int vis[])
    {
        vis[node]=1;
        queue<pair<int,int>> q;
        q.push({node,-1});
        
        while(!q.empty()){
            
            int frontNode=q.front().first;
            int prevNode=q.front().second;
            q.pop();
            
            for(int i=0;i<adj[frontNode].size();i++){
                int nbr=adj[frontNode][i];
                if(nbr!=prevNode){
                    if(vis[nbr]){
                        return true;
                    }
                    else{
                        q.push({nbr,frontNode});
                        vis[nbr]=true;
                    }
                }
                // if(!vis[nbr]){
                //     q.push({nbr,frontNode});
                //     vis[nbr]=1;
                // }
                // else if(nbr!=prevNode){
                //     return true;
                // }
                
            }
        }
                
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(checkCycle(adj,i,V,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends