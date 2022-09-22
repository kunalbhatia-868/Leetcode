class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxCount=0;
        unordered_map<char,bool> strMap;
        int i=0,j=0;
        while(j<s.size())
        {
            if(strMap.count(s[j]))
            {   
                while(s[i]!=s[j])
                {
                    strMap.erase(s[i]);
                    i++;
                }
                i++;
            }
            else
            {
                strMap[s[j]]=true;
            }
            maxCount=max(maxCount,j-i+1);
            j++;
        }
        return maxCount;
    }
};