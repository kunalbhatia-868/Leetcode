class Solution {
public:
    void subsets(vector<int>& nums,int index,vector<int> temp,vector<vector<int>>& output)
    {
        if(index==nums.size())
        {
            output.push_back(temp);
            return; 
        }
        
        subsets(nums,index+1,temp,output);
        temp.push_back(nums[index]);
        subsets(nums,index+1,temp,output);
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> output;
        vector<int> temp;
        subsets(nums,0,temp,output);
        return output;
    }
};