class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1, maxprofit = 0;//buy at prices[l] and sell at prices[r]
        while(r<prices.size()-1){
            if(prices[r]>prices[l]) maxprofit = max(maxprofit,(prices[r] - prices[l]));
            else l = r;

            r++;
        }
        return maxprofit;
    }
};
