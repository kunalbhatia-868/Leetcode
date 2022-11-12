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
        
        
        combinationSum(candidates,target,index+1,output,temp);
        int curr=candidates[index];
        int factor=target/curr;
        for(int i=0;i<factor;i++)
        {        
            target-=curr;
            temp.push_back(curr);
            combinationSum(candidates,target,index+1,output,temp);
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        vector<int> temp;
        combinationSum(candidates,target,0,output,temp);
        return output;
    }
};