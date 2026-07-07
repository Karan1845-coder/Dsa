class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxprofit=0;
        int minprice=INT_MAX;
        for(int i=0;i<n;i++){
            minprice=min(minprice,prices[i]);
             int profit=prices[i]-minprice;
             maxprofit=max(profit,maxprofit);
               
            
        }
        return maxprofit;
    }
};