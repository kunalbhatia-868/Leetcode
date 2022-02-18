class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k>=num.size())
        {
            return "0";
        }   
        
        stack<char> stack;
        
        for(int i=0;i<num.size();i++)
        {
            while(!stack.empty() && stack.top()>num[i] && k>0)
            {
                stack.pop();
                k--;
            }
            stack.push(num[i]);
        }
        
        
        while(k>0)
        {
            stack.pop();
            k--;
        }
        
        if(stack.empty())
            return "0";
        
        string str="";
        while(!stack.empty())
        {
            str=stack.top()+str;
            stack.pop();
        }
        
        
        int j=0;
        while(str[j]=='0')
        {
            j++;
        }
        
        
        return str.substr(j)==""?"0":str.substr(j);
    }
};