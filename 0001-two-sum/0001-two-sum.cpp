class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> numMap;
        for(int i=0;i<nums.size();i++){
            int x=target-nums[i];
            if(numMap.count(x)){
                return {numMap[x],i};
            }
            numMap[nums[i]]=i;
        }
        return {};
    }
};