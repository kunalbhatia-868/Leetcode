class Solution {
public:
    int addDigits(int num) {
        if(num/10==0)
        {
            return num;
        }
        
        int dsum=0;
        int n=num;
        while(n)
        {
            dsum+=(n%10);
            n/=10;
        }
        
        return addDigits(dsum);
    }
};