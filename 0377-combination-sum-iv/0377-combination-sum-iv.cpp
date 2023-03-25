class Solution {
public:
//     int mem(vector<int>& nums, int target,vector<int>& dp){
//         if(target==0){
//             return 1;
//         } 
        
//         if(dp[target]!=-1){
//             return dp[target];
//         }
        
//         int ct=0;
//         for(auto num:nums){
//             if(target-num>=0){
//                 ct+=combinationSum4(nums,target-num);
//             }
//         }
//         dp[target]=ct;
//         return dp[target];
        
//     }
    // using dp of this code
    int combinationSum4(vector<int>& nums, int target) {
        vector<double> dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<target+1;i++){
            for(int j=0;j<nums.size();j++){
                if(i-nums[j]>=0){
                    dp[i]+=dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
};