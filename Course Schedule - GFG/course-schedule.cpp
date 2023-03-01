//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        int N=n;
        
        vector<int> inDeg(N,0);
        
        vector<int> adj[N];
        for(int i=0;i<prerequisites.size();i++){
            int v1=prerequisites[i][0];
            int v2=prerequisites[i][1];
            adj[v2].push_back(v1);
            inDeg[v1]++;
        }

        queue<int> q;
        for(int i=0;i<N;i++){
            if(inDeg[i]==0){
                q.push(i);
            }
        }

        vector<int> ordering;    
        while(!q.empty())
        {
            int fr=q.front();
            q.pop();

            for(auto nbr: adj[fr]){
                inDeg[nbr]--;
                if(inDeg[nbr]==0){
                    q.push(nbr);
                }
            }

            ordering.push_back(fr);
        }

        if(ordering.size()!=N){
            ordering.clear();       // ordering not possible
        }
        
        return ordering;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends