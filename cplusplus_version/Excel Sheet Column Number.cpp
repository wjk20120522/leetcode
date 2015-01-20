class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
		int val;
		for (char c : s) {
			val = c - 'A' + 1;
			res = res * 26 + val;
		}
		return res;
        
    }
};