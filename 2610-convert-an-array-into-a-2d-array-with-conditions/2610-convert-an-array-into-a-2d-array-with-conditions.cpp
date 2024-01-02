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
            for(auto it=nMap.begin();it!=nMap.end();it++){
                temp.push_back(it->first);
                
            }
            for(int i=0;i<temp.size();i++){
                nMap[temp[i]]-=1;
                if(nMap[temp[i]]==0){
                    nMap.erase(temp[i]);
                }
            }
            output.push_back(temp);
        }
                
        return output;
    }
};