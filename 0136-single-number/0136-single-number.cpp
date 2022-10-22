class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int tXor=0;
        for(int i=0;i<nums.size();i++){
            tXor^=nums[i];
        }
        return tXor;
    }
};