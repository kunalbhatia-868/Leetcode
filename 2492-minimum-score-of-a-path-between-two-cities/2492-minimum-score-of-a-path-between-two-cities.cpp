class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<roads.size();i++){
            
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        
        //basically the min path in the graph will be the score
        // in case of connected graph it is given that atleast 1 path bw 1 n is there
        // we will just traverse the connected component where 1 is there
        
        queue<int> q;
        vector<bool> vis(n,false);
        q.push(1);
        vis[1]=true;
        int minscore=INT_MAX;
        
        while(!q.empty())
        {
            int fr=q.front();
            q.pop();
            
            for(auto e:adj[fr]){
                int nbr=e.first;
                int score=e.second;
                minscore=min(minscore,score);
                
                if(!vis[nbr]){
                    vis[nbr]=true;
                    q.push(nbr);
                }
            }
        }   
        return minscore;
    }
};