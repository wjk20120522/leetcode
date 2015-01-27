class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) return 0;
		int profit = 0;
		int min, max;
		
		min = max = prices[0];

		for (int i=0; i<prices.size(); i++)
		{
			if (prices[i] - min > profit)
			{
				profit = prices[i] - min;
			}
			if (prices[i] < min)
			{
				min = prices[i];
			}
		}
		return profit;
    }
};