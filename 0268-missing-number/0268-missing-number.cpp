class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int numsXor=0,totalXor=0;
        for(int i=0;i<nums.size();i++)
        {
            numsXor^=nums[i];
        }
        for(int i=0;i<=nums.size();i++)
        {
            numsXor^=i;
        }
        return numsXor^totalXor;
    }
};