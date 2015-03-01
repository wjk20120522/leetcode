class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) return s;
		int len = s.length(), gap = nRows * 2 - 2;
		string res;
		for (int i = 0; i < nRows; i++) {
			for (int j = i; j < len; j += gap) {
				res += s[j];
				// if not the first or last row
				if (i!=0 && i!= nRows-1 && j + 2 * (nRows - i - 1) < len) {
					res += s[j + 2 * (nRows - i - 1)];
				}
			}
		}
		return res;
    }
};