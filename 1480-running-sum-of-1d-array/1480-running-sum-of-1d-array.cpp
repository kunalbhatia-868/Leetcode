class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> output;
        output.push_back(nums[0]);
        
        for(int i=1;i<nums.size();i++){
            output.push_back(output[i-1]+nums[i]);
        }
        return output;
    }
};