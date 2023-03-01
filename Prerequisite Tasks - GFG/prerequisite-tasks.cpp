//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    
	   // using kahn algo topological sort
        
        vector<int> inDeg(N,0);
        
        vector<int> adj[N];
        for(int i=0;i<prerequisites.size();i++){
            int v1=prerequisites[i].first;
            int v2=prerequisites[i].second;
            adj[v2].push_back(v1);
            inDeg[v1]++;
        }

        queue<int> q;
        for(int i=0;i<N;i++){
            if(inDeg[i]==0){
                q.push(i);
            }
        }

        int ct=0;    
        while(!q.empty())
        {
            int fr=q.front();
            q.pop();
            ct++;

            for(auto nbr: adj[fr]){
                inDeg[nbr]--;
                if(inDeg[nbr]==0){
                    q.push(nbr);
                }
            }
        }

        return ct==N;       // no cycle in directed graph thus possible as ordering can form
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends