class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int contentChildren = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int i=g.size()-1;
        int j=s.size()-1;
        
        while(i>=0 && j>=0)
        {
            if(s[j]>=g[i]){
                j--;
                i--;
                contentChildren++;
            }
            else{
                i--;
            }
            
        }
        return contentChildren;
    }
};



// 1 2 3 4 5 6 7 8 8 8 8
// 1 1 4 7 8 8

// 10 9 8 7
// 5 6 7 8

// 7 8 9 10
// 5 6 7 8     
