class Solution {
public:
    void combinationSum(vector<int>& candidates,int index, int target,vector<int> temp,vector<vector<int>>&output)
    {
        if(target==0)
        {
            output.push_back(temp);
            return ;
        }
        if(index==candidates.size())
        {
            return;    
        }
        
        combinationSum(candidates,index+1,target,temp,output);
        while(index<candidates.size() && target-candidates[index]>=0)
        {
            target-=candidates[index];
            temp.push_back(candidates[index]);
            combinationSum(candidates,index+1,target,temp,output);
        }
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>output;
        vector<int> temp;
        combinationSum(candidates,0,target,temp,output);
        return output;
    }
};