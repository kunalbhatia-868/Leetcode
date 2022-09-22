class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        int n=nums.size();
        
        if(n<3){
            return output;
        }
        sort(nums.begin(),nums.end());
        int j=0,k=0;
        for(int i=0;i<n-2;i++)
        {
            if(i!=0 && nums[i]==nums[i-1]){
                continue;
            }
            j=i+1;
            k=n-1;
            
            while(j<k)
            {
                int s=nums[i]+nums[j]+nums[k];
                
                if(s==0)
                {
                    output.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[j]==nums[j+1]){
                        j++;
                    }
                    j++;
                    
                    while(j<k && nums[k]==nums[k-1]){
                        k--;
                    }
                    k--;
                    
                }
                else if(s<0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        return output;
    }
};