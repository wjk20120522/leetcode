class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();

		int begin = 0;
		int before = n;

		int all = 0;

		while (before != begin)
		{
			all += gas[begin] - cost[begin];
			if (all >= 0)
			{
				begin++;
			}
			else
			{
				while (all <0 && before != begin)
				{
					before--;
					all += gas[before] - cost[before];

				}
				if (all >= 0) begin++;
			}
		}

		if (all >= 0) return before%n;
		return -1;
    }
    
};