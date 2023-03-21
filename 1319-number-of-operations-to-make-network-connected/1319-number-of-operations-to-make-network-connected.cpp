class Solution {
public:
    //count islands
    void dfs(vector<int> adj[],int src,vector<int>& vis){
        vis[src]=1;
        for(int nbr:adj[src]){
            if(!vis[nbr]){
                dfs(adj,nbr,vis);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){          // wires are less total computer-1
            return -1;
        }
        
        // to make connecttion bw n node atleast n-1 wires are required , else impossible
        
        vector<int> adj[n];
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);

        }
        
        // if there are atleast n-1 wires then we can just calculate no of island 
        // and give wires to connect then 
        // to connect k islands k-1 wires are needed eg ex 2 -> 3 islands connect via 2 wires
        
        int count=0;
        
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,i,vis);
                count++;
            }
        }
        
        return count-1;     // to connect k computer islands , k-1 wires needed
    }
};