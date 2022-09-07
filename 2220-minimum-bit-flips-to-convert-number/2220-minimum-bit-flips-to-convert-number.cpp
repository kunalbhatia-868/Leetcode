class Solution {
public:
    int countSetBits(int n)
    {
        int count=0;
        while(n!=0){
            int rsbm=n&(-n);
            count++;
            n&=(~rsbm);
        }
        return count;
    }
    int minBitFlips(int start, int goal) {
        return countSetBits(start^goal);
    }
};