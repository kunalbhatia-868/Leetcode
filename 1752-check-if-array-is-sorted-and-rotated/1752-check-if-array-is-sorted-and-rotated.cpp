class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        
        
        int k=0;
        while(k<n-1 && nums[k]<=nums[k+1]){
            k++;
        }
        if(k==n-1){
            return true;
        }
        
        int x=k+1;
        for(int i=0;i<n-1;i++)
        {
            if(nums[x%n]>nums[(x+1)%n]){
                
                return false;
            }
            x++;
        }
        return true;
        
        
        
    }
};