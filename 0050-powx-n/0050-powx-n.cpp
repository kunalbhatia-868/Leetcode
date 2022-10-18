class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        
        double ans=1;
        if(n%2 != 0){
          if(n>0){
              ans*=x;
          }
          else{
              ans*=(1/x);
          }
        }
        double temp= myPow(x,n/2);
        ans*=(temp*temp);
        return ans;
    }
};