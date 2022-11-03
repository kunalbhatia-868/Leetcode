class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }        
        
        int start=0;
        int end=n-1;
        
        
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            
            if(nums[start]<nums[end])     // already sorted
            {
                return nums[start];
            }
            
            if(nums[mid]<nums[(mid+1)%n] && nums[mid]<nums[(mid+n-1)%n])
            {
                return nums[mid];
            }
            
            if(nums[start]<=nums[mid])     //left sorted 
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return -1;
    }
};