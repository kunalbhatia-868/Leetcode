class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> map;
        for(int i=0;i<s.size();i++)
        {
            map[s[i]]++;
        }
        
        for(int i=0;i<t.size();i++)
        {
            if(!map.count(t[i]))
            {
                return false;
            }
            else
            {
                map[t[i]]--;
                if(map[t[i]]==0){
                    map.erase(t[i]);
                }
            }
        }
        
        return map.size()==0;
    }
};