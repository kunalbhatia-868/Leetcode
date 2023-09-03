class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        
        int n=x;
        long long rev=0;
        while(n){
            int rem=n%10;
            n/=10;
            rev=rev*10+rem;
        }
        return rev==x;
    }
};