class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int,int> chMap;
        for(int i=0;i<s.size();i++)
        {
            chMap[s[i]]++;
        }
        for(int i=0;i<s.size();i++)
        {
            if(chMap[s[i]]==1){
                return i;
            }
        }
        
        return -1;
        
    }
};