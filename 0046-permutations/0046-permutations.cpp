class Solution {
public:
    void swapIndex(vector<int>& nums,int i,int j)
    {
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
    void permute(vector<int>& nums,int index,vector<vector<int>>& output)
    {
        if(index==nums.size()){
            output.push_back(nums);
            return;
        }
        
        for(int i=index;i<nums.size();i++)
        {
            swapIndex(nums,index,i);
            permute(nums,index+1,output);
            swapIndex(nums,index,i);
        }
        
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> output;
        permute(nums,0,output);
        return output;
    }
};