class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        // 0 -> {0} so 1
        // 00 -> {0} {0} {0,0} -> 2 ones + 1 twos
        // 000 -> {0} {0} {0} {0,0} {0,0} {0,0,0} -> 3 ones + 2 twos + 1 thrice
        // 0000 -> 1 grp of 4s + 2 group of threes + 3 grp of twos + 4 grp of ones
        // count the subarray and add their summation(1-n) to sum ex 4 size 0 subarray will have 10 subarray
        // sumattion till 1 - n is n(n+1)/2 ex 4(5)/2 -> 10
        
        long long zeroCount=0;
        long long totalSubArray=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zeroCount++;
            }
            else if(zeroCount>0){
                totalSubArray+=((zeroCount*(zeroCount+1))/2);
                zeroCount=0;
            }
        }
        
        // for leading 0's 
        if(zeroCount>0){
            totalSubArray+=((zeroCount*(zeroCount+1))/2);
            zeroCount=0;
        }
        
        return totalSubArray;
    }
};