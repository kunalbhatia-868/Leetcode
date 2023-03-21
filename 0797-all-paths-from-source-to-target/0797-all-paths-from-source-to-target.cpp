class Solution {
public:
    void dfs(vector<int> graph[],vector<bool>& vis,int src,int dest,vector<int>& temp,vector<vector<int>>& paths)      {
        if(src==dest){
            paths.push_back(temp);
            return;
        }    
        
        vis[src]=true;
        
        for(int nbr:graph[src]){
            if(!vis[nbr]){
                temp.push_back(nbr);
                dfs(graph,vis,nbr,dest,temp,paths);
                temp.pop_back();
            }
        }
        vis[src]=false;
    }
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> adj[graph.size()];
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        
        vector<bool> vis(graph.size(),false);
        int source=0;
        int destination=graph.size()-1;
        vector<vector<int>> paths;
        vector<int> temp;
        temp.push_back(source);
        
        dfs(adj,vis,source,destination,temp,paths);
        
        return paths;
    }
};