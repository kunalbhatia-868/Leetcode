class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0;
        while(nums[i]>0)
        {
            nums[i]=-nums[i];
            i=abs(nums[i]);
        }
        return i;
    }
};