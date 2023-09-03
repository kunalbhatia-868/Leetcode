class Solution {
public:
    int reverse(int x) {
        long long int rev=0;
        long long num=abs(x);
        int sign= x>=0?1:-1;
        while(num!=0){
            int rem=num%10;
            num/=10;
            rev=rev*10+rem;
            if(rev>INT32_MAX || (sign==-1 && rev-1>INT_MAX)){
                return 0;
            }
        }
        
        return rev*sign;
    }
};