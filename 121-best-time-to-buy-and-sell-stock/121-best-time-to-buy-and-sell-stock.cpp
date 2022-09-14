class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMin=prices[0];
        int maxProfit=0;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]>currMin)
            {
                maxProfit=max(maxProfit,prices[i]-currMin);
            }
            else
            {
                currMin=min(currMin,prices[i]);
            }
        }
        return maxProfit;
    }
};