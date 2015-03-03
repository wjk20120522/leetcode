class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int N = gas.size();
		int begin = N - 1, end = 0, sum = gas[begin] - cost[begin];
		while (begin > end) {
			if (sum < 0) {
				begin--;
				sum += gas[begin] - cost[begin];
			}
			else {
				sum += gas[end] - cost[end];
				end++;
			}
		}
		return sum >= 0 ? begin : -1;
	}
};