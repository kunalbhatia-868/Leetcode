class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> map;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            int curr=nums2[i];
            if(st.size()==0){
                
                map[nums2[i]]=-1;
            }
            else if(st.top()<=curr)
            {
                while(st.size()>0 && st.top()<=curr){
                    st.pop();
                }
                
                if(st.size()==0){
                    
                    map[nums2[i]]=-1;
                }
                else{
                    map[nums2[i]]=st.top();
                }
            }
            else{
                map[nums2[i]]=st.top();
            }
            
            st.push(nums2[i]);
        }
        
        vector<int> output;
        for(int i=0;i<nums1.size();i++){
            output.push_back(map[nums1[i]]);
        }
        return output;
        
    }
};