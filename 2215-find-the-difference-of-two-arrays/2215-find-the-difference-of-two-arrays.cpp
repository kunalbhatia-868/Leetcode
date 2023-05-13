class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nMap1;
        unordered_map<int,int> nMap2;
        
        for(int i=0;i<nums1.size();i++)
        {
            nMap1[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            nMap2[nums2[i]]++;
        }
    
        
        vector<int> aMinusB;
        for(int i=0;i<nums1.size();i++){
            if(!nMap2.count(nums1[i])){
                aMinusB.push_back(nums1[i]);
                nMap2[nums1[i]]=true;
            }
        }
        
        vector<int> bMinusA;
        for(int i=0;i<nums2.size();i++){
            if(!nMap1.count(nums2[i])){
                
                bMinusA.push_back(nums2[i]);
                nMap1[nums2[i]]=true;
            }
        }
        
        return {aMinusB,bMinusA};
    }
};