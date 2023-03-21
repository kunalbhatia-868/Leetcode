class Solution {
public:
    void dfs(vector<int> adj[],int src,vector<int>& vis){
        vis[src]=1;
        for(int nbr:adj[src]){
            if(!vis[nbr]){
                dfs(adj,nbr,vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int count=0;
        
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,i,vis);
                count++;
            }
        }
        
        return count;
    }
};