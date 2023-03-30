class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            if(ch=='{' || ch=='[' || ch=='('){
                st.push(ch);
            }
            else if(ch==')' &&(st.empty() || st.top()!='(')){
                return false;
            }
            else if(ch=='}' &&(st.empty() || st.top()!='{')){
                return false;
            }
            else if(ch==']' &&(st.empty() || st.top()!='[')){
                return false;
            }
            else{
                st.pop();
            }
        }
        
        return st.size()==0;
    }
};