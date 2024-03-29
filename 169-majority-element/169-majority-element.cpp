class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curr=nums[0];
        int count=1;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==curr)
            {
                count++;
            }
            else
            {
                count--;
                if(count==0)
                {
                    curr=nums[i];
                    count=1;
                }
            }
        }
        
        count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(curr==nums[i]){
                count++;
            }
        }
        cout<<curr<<count;
        return count>nums.size()/2?curr:-1;
    }
};