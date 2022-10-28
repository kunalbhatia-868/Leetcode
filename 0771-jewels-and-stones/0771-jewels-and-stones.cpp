class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count=0;
        unordered_map<char,bool> map;
        for(int i=0;i<jewels.size();i++)
        {
            map[jewels[i]]=true;
        }
        
        for(int i=0;i<stones.size();i++)
        {
            if(map.count(stones[i]))
            {
                count++;
            }
        }
        
        
        return count;
    }
};