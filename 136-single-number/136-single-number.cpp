class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> numSet;
        for(auto n:nums)
        {
            if(numSet.find(n)==numSet.end())
            {
                numSet.insert(n);
            }
            else
            {
                numSet.erase(n);
            }
        }
        return *numSet.begin();
    }
};