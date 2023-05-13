class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool isZero=false;
        bool neg=false;
        for(auto n:nums){
            if(n==0){
                isZero=true;
                break;
            }
            else if(n<0){
                neg=neg==true?false:true;
            }
            
        }
        
        if(isZero){
            return 0;
        }
        else{
            return neg==true?-1:1;
        }
    }
};