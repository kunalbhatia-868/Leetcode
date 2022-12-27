//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool valid(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<valid(str)<<endl;
    }
    return 0;
}
// } Driver Code Ends


bool valid(string s)
{
    // code here
    stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            char curr=s[i];
            if(curr=='{' || curr=='[' || curr=='(')
            {
                st.push(curr);
            }
            else
            {
                if(curr=='}')
                {
                    if(st.empty() || st.top()!='{'){
                        return false;
                    }
                    else{
                        st.pop();
                    }
                }
                else if (curr==']'){
                    if(st.empty() || st.top()!='['){
                        return false;
                    }
                    else{
                        st.pop();
                    }
                }
                else{
                    if(st.empty() || st.top()!='('){
                        return false;
                    }
                    else{
                        st.pop();
                    }
                }
            }
        }
        return st.size()==0;
}