/*
use anothrer vector to save the result
 */
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        bool allNine = true;
		for (int d : digits) {
			if (d != 9) {
				allNine = false; break;
			}
		}
		vector<int> res(digits.size());
		if (allNine) res.resize(digits.size() + 1);
		int end = res.size() - 1;
		digits[digits.size() - 1]++;

		for (int i = digits.size() - 1; i >= 0; i--, end--) {
			res[end] = digits[i] % 10;
			if (digits[i] >= 10) {
				if (i > 0)
					digits[i - 1] ++;
				else
					res[--end] = 1;
			}
		}
		return res;
    }
};


/*
do arithmetic in original vector
 */
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        bool carry = true;
		for (int i = digits.size() - 1; i >= 0 && carry; i--) {			
			digits[i] = (digits[i]+1) % 10;
			carry = (digits[i] == 0);
		}
		if (carry)
			digits.insert(digits.begin(), 1);
		return digits;
    }
};
