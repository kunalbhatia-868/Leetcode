class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> nMap;
        for(int i=0;i<nums.size();i++){
            nMap[nums[i]]++;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;        // min heap
        // keep min at top of size k
        for(auto [key,value]:nMap){
            if(pq.size()<k){
                pq.push({value,key});
            }
            else{
                int topCount=pq.top().first;
                if(topCount<value){
                    pq.pop();
                    pq.push({value,key});
                }
            }
        }
        
        vector<int> output(k);
        int idx=k-1;
        while(!pq.empty()){
            int val=pq.top().second;
            pq.pop();
            output[idx]=val;
            idx--;
        }
        
        return output;
    }
};