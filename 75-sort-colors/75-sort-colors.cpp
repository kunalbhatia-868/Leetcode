class Solution {
public:
    void swap(vector<int>& nums,int i, int j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
    void sortColors(vector<int>& nums) {
        int low=0;
        int mid=0;
        int high=nums.size()-1;
        while(mid<=high)
        {
            if(nums[mid]==2)
            {
                swap(nums,mid,high);
                high--;
            }
            else if(nums[mid]==0)
            {
                swap(nums,mid,low);
                low++;
                mid++;
            }
            else
            {
                mid++;
            }
        }
    }
};