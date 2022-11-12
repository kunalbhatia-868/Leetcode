class Solution {
public:
    void combinationSum(vector<int>& candidates, int target,int index, vector<vector<int>>& output,vector<int> temp){
        if(candidates.size()==index)
        {
            if(target==0){
                output.push_back(temp);
            }
            return;
        }
        
        
        if(candidates[index]<=target){
            temp.push_back(candidates[index]);
            combinationSum(candidates,target-candidates[index],index,output,temp);    
            temp.pop_back();
        }
        combinationSum(candidates,target,index+1,output,temp);
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        vector<int> temp;
        combinationSum(candidates,target,0,output,temp);
        return output;
    }
};