class Solution {
public:
    bool canJump(vector<int>& nums) {
        // greedy approach
        // approach - think reverse of dp
        // start from index n-2 second last and think is you can reach the last index 
        // if you can reach get to last from second last index
        // then thik of second last index as last index
        // eg [2,3,1,1,4]  -> possible to reach from 3 index to 4 index as nums[3] is 1 so 3+1=4 at max is reachable
        // chnage if end is good as if you can reach lets say 13 index from 8 and 12 , so set it to 12 and then it woldn't matter for 8
        // as if 8 can reach 13 it can also reach 12 
        
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