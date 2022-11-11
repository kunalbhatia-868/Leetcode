class Solution {
public:
        void generateParenthesis(int ob, int cb,string curr,vector<string>& output)
        {
            if(ob==0 && cb==0)
            {
                output.push_back(curr);    
            }        
            
            if(ob>0)
            {
                generateParenthesis(ob-1,cb,curr+"(",output);
            }
            
            if(cb>ob && cb>0)
            {
                generateParenthesis(ob,cb-1,curr+")",output);
            }
        }
    
        vector<string> generateParenthesis(int n) {
        vector<string> output;
        generateParenthesis(n,n,"",output);
        return output;
    }
};