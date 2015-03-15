class Solution {
public:
    vector<string> letterCombinations(string digits) {
		string digit2str[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		vector<string> res, tmp;
		if (digits.length() == 0) return res;
		res.push_back("");
		for (int i = 0; i < digits.length(); i++) {
			tmp.clear();
			int num = digits[i] - '0';
			for (int j = 0; j < digit2str[num].length(); j++) {
				for (string str : res) {
					tmp.push_back(str + (digit2str[num][j]));
				}
			}
			res = tmp;
		}
		return res;
	}
};