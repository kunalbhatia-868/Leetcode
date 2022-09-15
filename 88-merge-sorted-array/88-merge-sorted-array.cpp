class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0)
        {
            nums1=nums2;
            return;
        }
        else if(n==0){
            return;
        }
        
        vector<int> output;
        int i=0,j=0;
        while(i<m && j<n)
        {
            if(nums1[i]<nums2[j])
            {
                output.push_back(nums1[i]);
                i++;
            }
            else
            {
                output.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m)
        {
            output.push_back(nums1[i]);
            i++;
        }
        while(j<n)
        {
            output.push_back(nums2[j]);
            j++;
        }
        
        
        for(i=0;i<m+n;i++)
        {
            nums1[i]=output[i];
        }
    }
};