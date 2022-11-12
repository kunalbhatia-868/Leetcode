class Solution {
public:
    void combinationSum3(int k, int n,int start,vector<vector<int>>& output,vector<int> temp) {
        if(k==0)
        {
            if(n==0){
                output.push_back(temp);
            }
            return;
        }
        
        for(int i=start;i<=9;i++)
        {
            temp.push_back(i);
            combinationSum3(k-1,n-i,i+1,output,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> output;
        vector<int> temp;
        combinationSum3(k,n,1,output,temp);
        return output;
    }
};