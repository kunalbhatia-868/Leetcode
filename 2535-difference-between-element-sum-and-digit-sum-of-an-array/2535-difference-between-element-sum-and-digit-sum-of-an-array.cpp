class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int es=0;
        int ds=0;
        for(int i=0;i<nums.size();i++){
            es+=nums[i];
            int n=nums[i];
            while(n){
                int rem=n%10;
                ds+=rem;
                n/=10;
            }
        }
        return abs(es-ds);
    }
};