class Solution {
public:
    void subsetsWithDup(vector<int>& nums,int index,vector<int> temp,vector<vector<int>>& output){
        if(index==nums.size())
        {
            output.push_back(temp);
            return;
        }
        
        
        temp.push_back(nums[index]);
        subsetsWithDup(nums,index+1,temp,output);
        temp.pop_back();
        
        int i=index+1;
        while(i<nums.size() && nums[i]==nums[i-1]){
            i++;
        }
        
        subsetsWithDup(nums,i,temp,output);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> output;
        vector<int> temp;
        subsetsWithDup(nums,0,temp,output);
        return output;
    }
};