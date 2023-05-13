class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool neg=false;
        for(auto n:nums){
            if(n==0){
                return 0;
            }
            else if(n<0){
                neg=neg==true?false:true;
            }
            
        }
        
        return neg==true?-1:1;
    }
};