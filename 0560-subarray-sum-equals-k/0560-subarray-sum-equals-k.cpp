class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int N=nums.size();
        int count=0;
        unordered_map<int,int> numMap;
        numMap[0]=1;
        
        int currSum=0;
        for(int i=0;i<N;i++)
        {
            currSum+=nums[i];
            if(numMap.count(currSum-k)){
                count+=numMap[currSum-k];
            }
            
            if(numMap.count(currSum)){
                numMap[currSum]++;
            }
            else{
                numMap[currSum]=1;
            }
        }
        
        return count;
    }
};