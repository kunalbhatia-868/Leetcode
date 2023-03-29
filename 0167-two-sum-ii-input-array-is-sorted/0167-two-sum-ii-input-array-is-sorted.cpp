class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> numMap;
        for(int i=0;i<numbers.size();i++){
            int x=target-numbers[i];
            if(numMap.count(x)){
                return {numMap[x]+1,i+1};
            }
            numMap[numbers[i]]=i;
        }
        return {};
    }
};