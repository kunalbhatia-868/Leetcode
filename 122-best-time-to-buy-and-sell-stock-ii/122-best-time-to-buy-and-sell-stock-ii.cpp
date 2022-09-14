class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int currMin=prices[0];
        
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>currMin)
            {
                maxProfit+=(prices[i]-currMin);
            }
            currMin=prices[i];
        }
        
        return maxProfit;
    }
};