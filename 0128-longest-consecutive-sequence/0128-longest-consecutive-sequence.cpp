class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> nMap;
        for(int i=0;i<nums.size();i++){
            nMap[nums[i]]=true;
        }
        for(int i=0;i<nums.size();i++){
            if(nMap.count(nums[i]-1)){
                nMap[nums[i]]=false;
            }
        }
        
        int maxCount=0;
        for(int i=0;i<nums.size();i++){
            if(nMap[nums[i]]==true){
                int val=nums[i];
                int count=0;
                while(nMap.count(val)){
                    val+=1;
                    count+=1;
                }
                maxCount=max(maxCount,count);
            }
        }
        return maxCount;
    }
};