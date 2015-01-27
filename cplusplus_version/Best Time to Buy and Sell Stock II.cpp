class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
		int sum_profit = 0;
		int min, max;
		if (prices.size() == 0) return 0;

		min = max = prices[0];

		for (int i=0; i<prices.size(); i++)
		{
			if (prices[i] - min > profit)
			{
				profit = prices[i] - min;
				max = prices[i];
			}
			
			if (prices[i] < max)
			{
				sum_profit += profit;
				profit = 0;
				max = min = prices[i];
			}
		}
		//此处需要考虑结束时最后一个profit没有加到sum_profit里面。
		// 比如 [1, 5, 2, 4, 6]
		return sum_profit+profit;
    }
};