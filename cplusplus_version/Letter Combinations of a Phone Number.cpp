class Solution {
public:
    vector<string> letterCombinations(string digits) {
		string alphs[] = { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		vector<string>res,tmp;
		if (digits == "") return res;
		res.push_back("");
		for (int i = 0; i < digits.length(); i++) {
			int num = digits[i] - '0';
			for (string str : res) {
				for (int j = 0; j < alphs[num].length(); j++) {
					tmp.push_back(str + alphs[num][j]);
				}
			}
			res = tmp;
			tmp.clear();
		}
		return res;
	}
};