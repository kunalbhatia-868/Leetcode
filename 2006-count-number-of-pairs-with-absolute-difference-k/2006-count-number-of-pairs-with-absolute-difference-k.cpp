class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> nMap;        
        int count=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nMap.count(nums[i]+k))
            {
                count+=nMap[nums[i]+k];
            }
            if(nMap.count(nums[i]-k))
            {
                count+=nMap[nums[i]-k];
            }
            nMap[nums[i]]+=1;
        }
        return count;
    }
};