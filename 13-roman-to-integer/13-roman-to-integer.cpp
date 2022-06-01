class Solution {
public:
    int romanToInt(string s) {
        int output;
        unordered_map<char,int> romanMap={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        
        
        for(int i=0;i<s.size()-1;i++)
        {
            if(romanMap[s[i]]<romanMap[s[i+1]])
            {
                output-=romanMap[s[i]];
            }    
            else
            {
                output+=romanMap[s[i]];
            }
        }
        
        output+=romanMap[s[s.size()-1]];
        
        
        
        return output;
    }
};