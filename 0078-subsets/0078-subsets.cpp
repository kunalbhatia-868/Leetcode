class Solution {
public:
    void subsets(vector<int>& nums,int index,vector<vector<int>>& output) {
        if(index==nums.size()){
            output.push_back({});
            return;
        }
        
        subsets(nums,index+1,output);
        int n=output.size();
        for(int i=0;i<n;i++)
        {
            vector<int> temp=output[i];
            temp.push_back(nums[index]);
            output.push_back(temp);
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        subsets(nums,0,output);
        return output;
    }
};