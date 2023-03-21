class Solution {
public:
    bool dfs(vector<int> graph[],vector<bool>& vis,int src,int dest){
        if(src==dest){
            return true;
        }    
        
        vis[src]=true;
        for(int nbr:graph[src]){
            if(!vis[nbr] && dfs(graph,vis,nbr,dest)){
                return true;
            }
        }
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);

        }
        
        vector<bool> vis(n,false);
        return dfs(adj,vis,source,destination);
    }
};