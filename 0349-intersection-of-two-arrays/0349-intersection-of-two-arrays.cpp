class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool> map;
        for(int i=0;i<nums1.size();i++)map[nums1[i]]=true;
        
        
        vector<int> output;
        for(int i=0;i<nums2.size();i++){
            if(map.count(nums2[i])){
                map.erase(nums2[i]);
                output.push_back(nums2[i]);
            }
        }
        return output;
    }
};