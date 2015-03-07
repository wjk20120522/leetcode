class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maxprofit = 0, minprice = INT_MAX;
		for (int i = 0; i < prices.size(); i++) {
			minprice = min(minprice, prices[i]);
			if (prices[i] > minprice) {	// get that profit if you can
				maxprofit += prices[i] - minprice;
				minprice = prices[i];
			}
		}
		return maxprofit;
    }
};


/*
short code
 */
class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int maxprofit = 0;
		for (int i = 1; i < prices.size(); i++) {
			maxprofit += (prices[i]> prices[i - 1] ? prices[i] - prices[i - 1] : 0);
		}
		return maxprofit;
	}
};