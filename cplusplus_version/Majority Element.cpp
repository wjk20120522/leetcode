/*
use stack to save the major element
 */
class Solution {
public:
	int majorityElement(vector<int> &num) {
		stack<int> s;
		for (int i = 0; i < num.size(); i++) {
			if (s.empty() || num[i] == s.top()) {
				s.push(num[i]);
			}
			else {
				s.pop();
			}
		}
		return s.top();

	}
};


/*
same idea but use one variable
*/
class Solution {
public:
    int majorityElement(vector<int> &num) {
        int major , majornum = 0;
		for (int n : num) {
			if (majornum == 0) {
				major = n;
				majornum = 1;
			}
			else if (n == major) {
				majornum++;
			}
			else {
				majornum--;
			}
		}
		return major;
    }
};


/*
you can use sort but it don't get the lowest time complexity
*/
class Solution {
public:
	int majorityElement(vector<int> &num) {
		sort(num.begin(), num.end());
		return num[num.size() / 2];
	}
};


/*
bit manipulation, but it is not that fast
 */
class Solution {
public:
	int majorityElement(vector<int> &num) {
		int ret = 0;
		for (int i = 0; i < 32; i++) {
			int ones = 0, zeros = 0;
			for (int j = 0; j < num.size(); j++) {
				if ((num[j] >> i) & 1) ones++;
				else zeros++;
			}
			if (ones > zeros) ret |= (1 << i);
		}
		return ret;
	}
};