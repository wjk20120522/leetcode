class Solution {
public:
    int maxProfit(vector<int> &prices) {
    	int maxprofit = 0, minprice = INT_MAX;
		for (int i = 0; i < prices.size(); i++) {
			minprice = min(prices[i], minprice);
			maxprofit = max(prices[i] - minprice, maxprofit);	
		}
		return maxprofit;
    }
};