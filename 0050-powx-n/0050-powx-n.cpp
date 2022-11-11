class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        
        double temp=1;
        if(n%2!=0)
        {
            if(n>0)
            {
                temp*=x;        
            }
            else
            {
                temp*=(1/x);
            }
        }
        
        double rest=myPow(x,n/2);
        temp=temp*rest*rest;
        return temp;
    }
};