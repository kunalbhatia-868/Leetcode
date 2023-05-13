class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 1. We have to find next lexiographically next combination
        // 2. that is the smallest larger number we can form with this combination
        // // 3. Steps:
        //     - first We have have to find index at which from behind the arr[i]<arr[i+1] 
        //     because It gives after which we can find change as all elements after this index will be like a[i]<a[i+1]<a[i+2]
        //     - then swap it with the the smallest number that is larger then idx value start find from last index
        //         this will help us replace this idx with larger digit that is smallest of choices to find as per request
        //     - Now after swap sort from next index to idx till last as that will give the smallest larger value
        
        int idx=-1;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1]){
                idx=i;
                break;
            }
        }
        
        if(idx==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        for(int i=nums.size()-1;i>idx;i--)
        {
            if(nums[idx]<nums[i]){
                int temp=nums[i];
                nums[i]=nums[idx];
                nums[idx]=temp;
                break;
            }
        }
        
        sort(nums.begin()+idx+1,nums.end());
        
        
    }   
};