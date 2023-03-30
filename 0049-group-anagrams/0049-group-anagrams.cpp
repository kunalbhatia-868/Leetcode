class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> output;
        map<map<char,int>,vector<string>> strMap;
        
        for(int i=0;i<strs.size();i++){
            string curr=strs[i];
            map<char,int> chMap;
            for(char ch:curr){
                chMap[ch]++;
            }
            if(strMap.count(chMap)){
                strMap[chMap].push_back(curr);
            }
            else{
                strMap[chMap]={curr};   
            }
        }
        
        for(auto [key,list]:strMap){
            output.push_back(list);
        }
        
        return output;
    }
};