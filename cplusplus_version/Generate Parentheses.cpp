class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> res;
		generateParenthesis(n, n, res, "");
		return res;
	}

	void generateParenthesis(int left, int right, vector<string>&res, string tmp) {
		if (left == 0 && right == 0) {
			res.push_back(tmp); return;
		}
		if (left > 0) {
			generateParenthesis(left - 1, right, res, tmp + "(");
		}
		if (right > left) {
			generateParenthesis(left, right - 1, res,  tmp + ")");
		}
	}
};