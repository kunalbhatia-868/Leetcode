class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0,zeroes=0,ones=0,i=0,maxOnes=0;
        
        while(i<nums.size())   
        {
            if(nums[i]==1)
            {
                ones++;
                maxOnes=max(maxOnes,zeroes+ones);
            }
            else
            {
                if(zeroes<k){
                    zeroes++;
                    maxOnes=max(maxOnes,zeroes+ones);
                }
                else
                {
                    while(nums[start]!=0)
                    {
                        start++;
                        ones--;
                    }   
                    start++;
                }
            }
            i++;
        }
        
        return maxOnes;
    }
};