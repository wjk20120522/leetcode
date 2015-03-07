/*
sort it and find the two, O(NlgN), 17ms
 */
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
    	vector<int>dump = numbers;
		sort(dump.begin(), dump.end());
		int begin = 0, end = numbers.size() - 1;
		while (begin < end) {
			if (dump[begin] + dump[end] == target) break;
			else if (dump[begin] + dump[end] > target) end--;
			else begin++;
		}
		int first =0, second = 0;
		bool hasbegin = false, hasend = false;
		for (int i = 0; i < numbers.size(); i++) {
			if ( (!hasbegin &&numbers[i] == dump[begin]) || (!hasend && numbers[i] == dump[end]) ) {
				if (numbers[i] == dump[begin])  hasbegin = true;
				else hasend = true;
				if (first == 0) {
					first = i+1;
				}
				else {
					end = i + 1;
					vector<int>res;
					res.push_back(first); res.push_back(end);
					return res;
				}
			}
		}
    }
};


/*
use hashmap, O(N), 20ms
 */
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> mp;
		vector<int>res;
		for (int i = 0; i < numbers.size(); i++) {
			int tofind = target - numbers[i];
			if (mp.find(tofind) != mp.end()) {
				res.push_back(mp[tofind]);
				res.push_back(i + 1);
				return res;
			}
			mp[numbers[i]] = i + 1;
		}
    }
};