class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> arr=nums;
        sort(arr.begin(),arr.end());
        int i=0,j=arr.size()-1;
        while(i<j)
        {
             int currSum=arr[i]+arr[j];
             if(currSum==target)
             {
                 break;
             }
             
            if(currSum>target)
             {
                 j--;
             }
             else
             {
                 i++;
             }
        } 
        
        vector<int> output;
        for(int k=0;k<nums.size();k++)
        {
            if(nums[k]==arr[j] |  nums[k]==arr[i])
            {
                output.push_back(k);
            }
        }
        return output;
    }
};