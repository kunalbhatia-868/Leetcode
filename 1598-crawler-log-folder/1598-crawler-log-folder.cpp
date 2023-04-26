class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        stack<int> st;
        int count=0;
        
        for(int i=0;i<logs.size();i++){
            if(logs[i]=="../")
            {
                if(!st.empty()){
                    st.pop();
                    count--;
                }
            }
            else if(logs[i]=="./"){
                continue;
            }
            else{
                st.push(1);
                count++;
            }
        }
        
        return count;
    }
};