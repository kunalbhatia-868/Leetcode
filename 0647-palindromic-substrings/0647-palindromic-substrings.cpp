class Solution {
public:
    bool isPalindromic(string s){
        int i=0;
        int j=s.size()-1;
        
        while(i<j)
        {
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int count=0;
    int countSubstrings(string s) {
        for(int i=0;i<s.size();i++)
        {
            for(int j=1;j<s.size()-i+1;j++)
            {
                if(isPalindromic(s.substr(i,j))){
                    count++;
                }
            }
        }  
        return count;
        
    }
};