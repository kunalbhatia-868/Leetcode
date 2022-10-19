class Solution {
public:
    void reverse(vector<int>& nums,int i,int j)
    {
        while(i<j){
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
            i++;
            j--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        if(nums.size()<2){
            return;
        }
        k=k%nums.size();
        if(k<0){
            k+=nums.size();
        }
        reverse(nums,0,nums.size()-1);
        reverse(nums,0,k-1);
        reverse(nums,k,nums.size()-1);
    }
};