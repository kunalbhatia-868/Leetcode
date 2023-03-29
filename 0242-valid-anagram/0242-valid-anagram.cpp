class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        {
            return false;
        }
        
        int charMap[26]={0};
        for(int i=0;i<s.size();i++){
            charMap[s[i]-'a']++;
        }
        
        for(int i=0;i<t.size();i++){
            if(charMap[t[i]-'a']>0){
                charMap[t[i]-'a']--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};