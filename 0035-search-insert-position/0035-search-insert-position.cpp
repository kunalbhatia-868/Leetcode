class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int pos=-1;
        int l=0;
        int h=nums.size()-1;
        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(nums[m]==target)
            {
                return m;
            }
            else if(nums[m]<target)
            {
                l=m+1;
            }
            else{
                pos=m;
                h=m-1;
            }
        }
        return pos==-1?nums.size():pos;
    }
};