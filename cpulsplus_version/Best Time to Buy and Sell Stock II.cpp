class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
		int sum_profit = 0;
		int min, max;
		if (prices.size() == 0) return 0;
		vector<int>::iterator it = prices.begin();
		
		min = max = *it;

		for (; it != prices.end(); it++)
		{
			if (*it - min > profit)
			{
				profit = *it - min;
				max = *it;
			}
			
			if (*it < max)
			{
				sum_profit += profit;
				profit = 0;
				max = min = *it;
			}
		}
		//此处需要考虑结束时最后一个profit没有加到sum_profit里面。
		// 比如 [1, 5, 2, 4, 6]
		return sum_profit+profit;
    }
};