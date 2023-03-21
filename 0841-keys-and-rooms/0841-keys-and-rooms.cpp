class Solution {
public:
    void dfs(vector<int> adj[],int src,vector<bool>& vis){
        vis[src]=true;
        
        for(int nbr:adj[src]){
            if(!vis[nbr]){
                dfs(adj,nbr,vis);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // just is connected graph question twisted in wordings
        int n=rooms.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<rooms[i].size();j++){
                adj[i].push_back(rooms[i][j]);
            }
        }
        vector<bool> vis(n,false);
        
        dfs(adj,0,vis);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};