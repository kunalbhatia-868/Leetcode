class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int totalBit=0;
        for(int i=1;i<=nums.size();i++){
            totalBit^=i;
        }
        
        for(int i=0;i<nums.size();i++){
            totalBit^=nums[i];
        }
        
        return totalBit;
    }
};