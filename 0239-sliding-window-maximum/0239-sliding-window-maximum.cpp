class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output;
        deque<int> dq;
        
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(dq.size()>0 && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            if(i>=k-1){
                if(dq.size()>0 && dq.front()<=i-k){
                    dq.pop_front();
                }
                output.push_back(nums[dq.front()]);    
            }
        }
        return output;
    }
};