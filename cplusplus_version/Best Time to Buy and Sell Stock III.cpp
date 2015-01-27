class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() <2) return 0;
        vector<int> leftMaxProfit(prices.size(), 0);
        //vector<int> rightProfit(prices.size(), 0);

        // left to right , calculate the maxProfit for each index
        int leftMin = prices[0];
        int leftProfit = 0;
        for(int i=0; i<prices.size(); i++) {
        	if(leftMin > prices[i]) leftMin = prices[i];
        	if(prices[i] - leftMin > leftProfit)
        		leftProfit = prices[i] - leftMin;
        	leftMaxProfit[i] = leftProfit;
        }

        int allMax = 0;    // the result

        //right to left
        int rightMax = prices[prices.size()-1];
        int rightProfit = 0;
        for(int i=prices.size()-1; i>=0; i--) {
        	if(rightMax < prices[i]) rightMax = prices[i];
        	if(rightMax - prices[i] > rightProfit)
        		rightProfit = rightMax - prices[i];
        	int currentProfit = rightProfit + (i>0 ? leftMaxProfit[i-1] : 0);
        	if(currentProfit > allMax)
        		allMax = currentProfit;
        }
        return allMax;

    }
};