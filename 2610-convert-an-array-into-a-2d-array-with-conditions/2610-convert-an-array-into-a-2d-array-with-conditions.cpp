class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> output;
        unordered_map<int,int> nMap;
        for(int i=0;i<nums.size();i++){
            nMap[nums[i]]++;
        }
        
        while(nMap.size()>0)
        {
            vector<int> temp;
            vector<int> eleToDel;
            
            for(auto num:nMap){
                int n=num.first;
                temp.push_back(n);
                
                nMap[n]--;
                if(nMap[n]==0){
                    eleToDel.push_back(n);
                }
            }
            
            for(auto ele:eleToDel){
                nMap.erase(ele);
            }
            
            output.push_back(temp);
        }
        
        return output;
    }
};