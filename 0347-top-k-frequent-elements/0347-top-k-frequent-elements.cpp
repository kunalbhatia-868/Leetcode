class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // using bucketsort or counting
        // 1. count existence of all the values
        // 2. a. we can make an array of size of all the values that occur like 3 occur 2 times and 4 occur 2 times
        //      but problem is there can be a number like million so we have to take an index millon to store its count
        //    b. other we can do is that max 1 value can occur is the size of the array as all values are same
        //        so lets take an array of nums.size()+1 as max a value can occur num.size() time
        //      and store as 2,3,4 occur once so store array [2,3,4] at index 1 and 5 occurs twice so [5] at 2 in 2d array
        
        unordered_map<int,int> nMap;
        for(int i=0;i<nums.size();i++){
            nMap[nums[i]]++;
        }
        
        int n=nums.size();
        vector<vector<int>> buckets(n+1);
        
        for(auto [key,value]:nMap){
            buckets[value].push_back(key);
        }
        
        // now that all values are added by their count index 
        // we need top k frequent so start from num.size()-1 to 0 and take k values store at any index
        
        vector<int> output;
        
        for(int i=n;i>=0;i--){
            if(output.size()>=k){
                break;
            }
            else if(buckets[i].size()>0){
                output.insert(output.end(),buckets[i].begin(),buckets[i].end());
            }
        }
        
        return output;
    }
};