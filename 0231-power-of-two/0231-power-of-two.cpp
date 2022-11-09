class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
        {
            return false;
        }
        
        double ans=log2(n);
        return (ans==int(ans));
         
        
    }
};