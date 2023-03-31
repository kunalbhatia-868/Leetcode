class Solution {
public:
    bool canJump(vector<int>& nums) {
        // greedy approach
        
        int n=nums.size();    
        int end=n-1;
        int i=n-2;
        while(i>=0){
            if(nums[i]+i>=end){
                end=i;
            }
            i--;
        }
        
        return end==0;
    }
};