class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //ideas is basic binary search as it is already sorted 
        //
        
        int i=0;
        int j=numbers.size()-1;
        while(i<j){
            int sum=numbers[i]+numbers[j];
            if(sum==target){
                return {i+1,j+1};           // indexed by 1 not 0 we are solving as 0 based only
            }
            else if(sum>target){
                j--;
            }
            else{
                i++;
            }
        }
        return {-1,-1};
    }
};